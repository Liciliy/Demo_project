#ifndef STRING_SERIALIZER
#define STRING_SERIALIZER
#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>
#include <string>

// NOTE: This class could be a singleton.
class StringSerializer final : public AbsDataSerializer
{
public:
    std::vector<uint8_t> serialize(const DataToSerialize& dts);

protected:
    std::string* currentlyProcessedValue;
    uint64_t currentValueByteSize;

    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;

};

#endif