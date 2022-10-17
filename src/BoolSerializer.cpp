#include "BoolSerializer.hpp"
#include "NotSupportedException.hpp"

#include <iostream>
std::vector<uint8_t> BoolSerializer::serialize(const DataToSerialize& dts)
{
    
    if (dts.getBool() == nullptr)
    {
        throw std::invalid_argument("Provided bool pointer is a nullptr.");
    }
    
    this->currentlyProcessedValue = *(dts.getBool() );
    
    auto result = std::vector<uint8_t>(HEADER_LENGTH_IN_BYTES);

    this->fillContainerWithHeader(result);

    return result;
}

uint64_t BoolSerializer::calculateDataLengthInBytes()
{
    throw NotSupportedException();
}

void BoolSerializer::fillContainerWithHeader(std::vector<uint8_t>&  headerContainer)
{
    uint8_t header = (BOOL_TYPE << TYPE_BIT_POS) | this->currentlyProcessedValue;

    headerContainer[0] = header;

}

void BoolSerializer::fillContainerWithLength(std::vector<uint8_t>& lengthContainer)
{
    throw NotSupportedException();
}

void BoolSerializer::fillContainerWithData(std::vector<uint8_t>& dataContainer)
{
    throw NotSupportedException();
}