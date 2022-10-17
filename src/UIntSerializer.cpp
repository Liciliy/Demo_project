#include "UIntSerializer.hpp"
#include "NotSupportedException.hpp"


std::vector<uint8_t> UIntSerializer::SerializeUInt(const uint64_t& valToSerialize)
{
    this->currentlyProcessedValue = valToSerialize;

    auto result = std::vector<uint8_t>(HEADER_LENGTH_IN_BYTES);

    this->fillContainerWithHeader(result);

    return result;
}

uint64_t UIntSerializer::calculateDataLengthInBytes()
{
    uint64_t result = UINT8_SIZE_IN_BYTES;

    if (this->currentlyProcessedValue & UINT64_MASK)
    {
        result = UINT64_SIZE_IN_BYTES;
    }
    else if (this->currentlyProcessedValue & UINT32_MASK)
    {
        result = UINT32_SIZE_IN_BYTES;
    }
    else if (this->currentlyProcessedValue & UINT16_MASK)
    {
        result = UINT16_SIZE_IN_BYTES;
    }

    return result;
}

void UIntSerializer::fillContainerWithHeader(std::vector<uint8_t>&  headerContainer)
{
    uint8_t header = (BOOL_TYPE << TYPE_BIT_POS) | this->currentlyProcessedValue;

    headerContainer[0] = header;

}

void UIntSerializer::fillContainerWithLength(std::vector<uint8_t>& lengthContainer)
{
    throw NotSupportedException();
}

void UIntSerializer::fillContainerWithData(std::vector<uint8_t>& dataContainer)
{
    
}