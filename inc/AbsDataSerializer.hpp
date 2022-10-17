#ifndef ABS_DATA_SERIALIZER
#define ABS_DATA_SERIALIZER

#include "AbsDataTranslator.hpp"
#include <cstdint>
#include <vector>

struct DataToSerialize;

class AbsDataSerializer : protected AbsDataTranslator
{
public:
    virtual std::vector<uint8_t> serialize(const DataToSerialize& dts) = 0;
    static uint8_t calculateUintByteSize(const uint64_t& intToCalc);

protected:

    virtual uint64_t calculateDataLengthInBytes() = 0;

    virtual void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) = 0;

    virtual void fillContainerWithLength(std::vector<uint8_t>& lengthContainer) = 0;

    virtual void fillContainerWithData(std::vector<uint8_t>& dataContainer) = 0;
};

#endif

