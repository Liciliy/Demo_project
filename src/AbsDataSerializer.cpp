#include <AbsDataSerializer.hpp>

uint8_t AbsDataSerializer::calculateUintByteSize(const uint64_t& intToCalc)
{
    uint64_t result = UINT8_SIZE_IN_BYTES;

    if (intToCalc & UINT64_MASK)
    {
        result = UINT64_SIZE_IN_BYTES;
    }
    else if (intToCalc & UINT32_MASK)
    {
        result = UINT32_SIZE_IN_BYTES;
    }
    else if (intToCalc & UINT16_MASK)
    {
        result = UINT16_SIZE_IN_BYTES;
    }

    return result;
}
