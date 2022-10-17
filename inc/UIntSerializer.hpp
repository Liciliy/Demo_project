#ifndef UINT_SERIALIZER
#define UINT_SERIALIZER

#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>

// NOTE: This class could be a singleton.
class UIntSerializer : public AbsDataSerializer
{
public:
    std::vector<uint8_t> SerializeUInt(const uint64_t& valToSerialize);

private:
    uint64_t currentlyProcessedValue;

    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;

};

#endif