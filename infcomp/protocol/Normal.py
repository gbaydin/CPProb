# automatically generated by the FlatBuffers compiler, do not modify

# namespace: protocol

import flatbuffers

class Normal(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsNormal(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Normal()
        x.Init(buf, n + offset)
        return x

    # Normal
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Normal
    def Mean(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # Normal
    def Std(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # Normal
    def Value(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

def NormalStart(builder): builder.StartObject(3)
def NormalAddMean(builder, mean): builder.PrependFloat64Slot(0, mean, 0.0)
def NormalAddStd(builder, std): builder.PrependFloat64Slot(1, std, 0.0)
def NormalAddValue(builder, value): builder.PrependFloat64Slot(2, value, 0.0)
def NormalEnd(builder): return builder.EndObject()