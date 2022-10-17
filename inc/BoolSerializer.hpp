#ifndef BOOL_SERIALIZER
#define BOOL_SERIALIZER
#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>

// NOTE: This class could be a singleton.
class BoolSerializer : public AbsDataSerializer
{
public:
    std::vector<uint8_t> SerializeBool(const bool& valToSerialize);

private:
    bool currentlyProcessedValue;
    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;
};


#endif