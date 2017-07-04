#include "cpprob/utils.hpp"

#include <execinfo.h>
#include <cxxabi.h>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include <boost/random/random_device.hpp>

namespace cpprob{

boost::random::mt19937& get_rng()
{
    static boost::random::mt19937 rng{detail::seeded_rng()};
    return rng;
}

std::string get_name_mangled (const char* s)
{
    auto str = std::string(s);
    auto first = str.find_last_of('(') + 1;
    auto last = str.find_last_of(')');

    return str.substr(first, last-first);
}

std::string get_name_demangled (const char* s)
{
    auto str = std::string(s);
    auto first = str.find_last_of('(') + 1;
    auto last = str.find_last_of(')');

    auto mas = str.find_last_of('+');

    int status;
    char* result = abi::__cxa_demangle(str.substr(first, mas-first).c_str(), nullptr, nullptr, &status);
    if (status == 0) {
        auto demangled = std::string(result);
        std::free(result);
        // Demangled function name + offset w.r.t the function return address
        return demangled + str.substr(mas, last - mas);
    }
    else {
        return get_name_mangled(s);
    }
}

bool in_namespace_models(const std::string & fun)
{
    // The only spaces before a word in a demangled name are in the arguments and in the name function
    // You also have spaces before a > when another > precedes it, but it's alright
    static std::regex r{"[^,] models::", std::regex::optimize};
    static std::smatch match;
    return std::regex_search(fun, match, r);
}

bool in_namespace_cpprob(const std::string & fun)
{
    // The only spaces before a word in a demangled name are in the arguments and in the name function
    // You also have spaces before a > when another > precedes it, but it's alright
    static std::regex r{"[^,] cpprob::", std::regex::optimize};
    static std::smatch match;
    return std::regex_search(fun, match, r);
}

std::string get_addr() {
    constexpr int buf_size = 100;
    static void *buffer[buf_size];
    char **strings;

    int nptrs = backtrace(buffer, buf_size);

    // We will not store the call to get_traces or the call to sample
    // We discard either observe -> sample_impl -> get_addr
    //            or     sample  -> sample_impl -> get_addr
    std::vector<std::string> trace_addrs;

    strings = backtrace_symbols(buffer, nptrs);
    if (strings == nullptr) {
        std::perror("backtrace_symbols");
        std::exit(EXIT_FAILURE);
    }

    // We will consider addresses in the range [begin, end]
    // Begin = 1 since the demangled name for get_addr is
    // cpprob::get_addr[abi:cxx11]()
    // so it does not show the std::string return type
    int begin = 1, end = nptrs - 1;

    // Discard calls inside the cpprob library
    while (begin != nptrs && in_namespace_cpprob(get_name_demangled(strings[begin]))) {
        ++begin;
    }

    if (begin == nptrs){
        std::cerr << "Entry function call to the cpprob library not found" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Discard calls outside of the models namespace
    while (end != -1 && !in_namespace_models(get_name_demangled(strings[end]))) {
        --end;
    }

    if (end == -1){
        std::cerr << "Entry call to model not found. Is the model in the namespace models?" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string ret = "[";
    // Stack calls are reversed. strings[0] is the current function call get_addr()
    if (begin <= end) {
        ret += get_name_demangled(strings[end]);
        --end;
    }
    for (auto i = end; i >= begin; i--){
        ret += ' ' + get_name_demangled(strings[i]);
    }
    ret += ']';
    std::free(strings);
    return ret;
}

}  // namespace cpprob
