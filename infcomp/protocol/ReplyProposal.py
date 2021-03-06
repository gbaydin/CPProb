# automatically generated by the FlatBuffers compiler, do not modify

# namespace: protocol

import flatbuffers

class ReplyProposal(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsReplyProposal(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = ReplyProposal()
        x.Init(buf, n + offset)
        return x

    # ReplyProposal
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # ReplyProposal
    def DistributionType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint8Flags, o + self._tab.Pos)
        return 0

    # ReplyProposal
    def Distribution(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            from flatbuffers.table import Table
            obj = Table(bytearray(), 0)
            self._tab.Union(obj, o)
            return obj
        return None

def ReplyProposalStart(builder): builder.StartObject(2)
def ReplyProposalAddDistributionType(builder, distributionType): builder.PrependUint8Slot(0, distributionType, 0)
def ReplyProposalAddDistribution(builder, distribution): builder.PrependUOffsetTRelativeSlot(1, flatbuffers.number_types.UOffsetTFlags.py_type(distribution), 0)
def ReplyProposalEnd(builder): return builder.EndObject()
