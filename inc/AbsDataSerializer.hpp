#ifndef ABS_DATA_SERIALIZER
#define ABS_DATA_SERIALIZER

#include "AbsDataTranslator.hpp"
#include <cstdint>
#include <vector>

class AbsDataSerializer : protected AbsDataTranslator
{
protected:

    virtual uint64_t calculateDataLengthInBytes() = 0;

    virtual void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) = 0;

    virtual void fillContainerWithLength(std::vector<uint8_t>& lengthContainer) = 0;

    virtual void fillContainerWithData(std::vector<uint8_t>& dataContainer) = 0;
};

#endif

