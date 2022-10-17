#ifndef INT_SERIALIZER
#define INT_SERIALIZER

#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>

// NOTE: This class could be a singleton.
class IntSerializer final : public AbsDataSerializer
{
public:
    std::vector<uint8_t> serialize(const DataToSerialize& dts);

private:
    int64_t currentlyProcessedValue;
    uint64_t currentValueByteSize;
    uint8_t currentValueIntID;

    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;

};

#endif