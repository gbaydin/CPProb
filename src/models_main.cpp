#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>

#include "cpprob/cpprob.hpp"
#include "cpprob/traits.hpp"
#include "cpprob/postprocess/stats_printer.hpp"

#include "models/models.hpp"
#include "models/poly_adjustment.hpp"

template <class F>
void execute (const F & f,
              const bool compile, const bool infer, const bool sis, const bool estimate,
              const std::string & model_name,
              const std::size_t n_samples,
              const std::size_t batch_size,
              const std::string & tcp_addr_compile,
              const std::string & tcp_addr_infer) {
    if (compile) {
        const auto dump_folder = model_name + "_traces";
        using namespace boost::filesystem;
        create_directory(path(dump_folder));
        cpprob::compile(f, tcp_addr_compile, dump_folder, batch_size);
    }

    const std::string csis_post = model_name + "_csis.post";
    const std::string sis_post = model_name + "_sis.post";

    if (infer || sis) {
        const auto observes_file = model_name + ".obs";

        using tuple_params_t = cpprob::parameter_types_t<F, std::tuple>;
        tuple_params_t observes;

        if (cpprob::parse_file(observes_file, observes)) {
            if (infer) {
                const cpprob::StateType state = cpprob::StateType::inference;
                cpprob::generate_posterior(f, observes, tcp_addr_infer, csis_post, n_samples, state);
            }
            if (sis) {
                const cpprob::StateType state = cpprob::StateType::importance_sampling;
                cpprob::generate_posterior(f, observes, tcp_addr_infer, sis_post, n_samples, state);
            }
        }

    }
    if (estimate) {
        bool none_exist = true;
        using namespace boost::filesystem;
        const path path_dump_folder (csis_post);
        auto print = [] (const std::string & file_name) {
            if (exists(path(file_name))) {
                cpprob::Printer p;
                p.load(file_name);
                p.print(std::cout);
                return false;
            }
            else {
                return true;
            }
        };
        none_exist &= print(csis_post);
        none_exist &= print(sis_post);
        if (none_exist) {
            std::cerr << "None of the files " << csis_post << " or " << sis_post << " were found.";
        }
    }
}


int main(int argc, const char* const* argv) {

    std::size_t n_samples, batch_size;
    bool compile = false, infer = false, sis = false, estimate = false, all = false;
    std::string model, tcp_addr_compile, tcp_addr_infer;
    std::vector<std::string> model_names {{"unk_mean", "unk_mean_rejection", "linear_gaussian", "hmm", "linear_regression"}};

    std::string all_model_names = model_names[0];
    for (std::size_t i = 1; i < model_names.size(); ++i) {
        all_model_names += '/' + model_names[i];
    }

    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options()
            ("model", po::value<std::string>(&model)->required()->value_name(all_model_names))
            ("compile", "Execute compilation.")
            ("infer", "Execute compiled inference.")
            ("sis", "Execute sequential importance sampling.")
            ("estimate", "Execute estimators.")
            ("all", "Execute all the options")
            ("batch_size", po::value<std::size_t>(&batch_size)->default_value(256))
            ("n_samples", po::value<std::size_t>(&n_samples)->default_value(1000), "Number of particles to be sampled from the posterior.")
            ("tcp_addr_compile", po::value<std::string>(&tcp_addr_compile)->default_value("tcp://0.0.0.0:5555"), "Address and port to connect with the NN at compile time.\n")
            ("tcp_addr_infer", po::value<std::string>(&tcp_addr_infer)->default_value("tcp://127.0.0.1:6666"), "Address and port to connect with the NN at inference time.\n")
            ;

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc),  vm);
        if (vm.count("help") != 0u) {
            std::cout << "CPProb Models" << std::endl
                      << desc << std::endl;
            return 0;
        }

        po::notify(vm); // throws on error, so do after help in case
        // there are any problems
    }
    catch(po::error& e) {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
        std::exit (EXIT_FAILURE);
    }
    compile = vm.count("compile");
    infer = vm.count("infer");
    sis = vm.count("sis");
    estimate = vm.count("estimate");
    all = vm.count("all");

    if (all && (compile || infer || sis || estimate)) {
        std::cerr << "Select all or some parts of the compilation, but not both."
                  << desc << std::endl;
        std::exit (EXIT_FAILURE);
    }
    if (all) {
        compile = true;
        infer = true;
        sis = true;
        estimate = true;
    }

    if (model == model_names[0] /* unk_mean */) {
        auto f = &models::gaussian_unknown_mean<>;
        execute(f, compile, infer, sis, estimate, model, n_samples, batch_size, tcp_addr_compile, tcp_addr_infer);
    }
    else if (model == model_names[1] /* unk_mean rejection */) {
        auto f = &models::normal_rejection_sampling<>;
        execute(f, compile, infer, sis, estimate, model, n_samples, batch_size, tcp_addr_compile, tcp_addr_infer);
    }
    else if (model == model_names[2] /* linear gaussian walk */) {
        auto f = &models::linear_gaussian_1d<50>;
        execute(f, compile, infer, sis, estimate, model, n_samples, batch_size, tcp_addr_compile, tcp_addr_infer);
    }
    else if (model == model_names[3] /* hmm */) {
        auto f = &models::hmm<16>;
        execute(f, compile, infer, sis, estimate, model, n_samples, batch_size, tcp_addr_compile, tcp_addr_infer);
    }
    else if (model == model_names[4] /* linear regression */) {
        auto f = &models::poly_adjustment<1, 6>; // Linear adjustment (Deg = 1, Points = 6)
        execute(f, compile, infer, sis, estimate, model, n_samples, batch_size, tcp_addr_compile, tcp_addr_infer);
    }
    else{
        std::cerr << "Incorrect model.\n\n"
                  << desc << std::endl;
        std::exit (EXIT_FAILURE);
    }
}