#include "UIntSerializer.hpp"
#include "NotSupportedException.hpp"

std::vector<uint8_t> UIntSerializer::serialize(const DataToSerialize& dts)
{
    if (dts.getUint() == nullptr)
    {
        throw std::invalid_argument("Provided UInt pointer is a nullptr.");
    }

    this->currentlyProcessedValue = *(dts.getUint());

    this->currentValueByteSize = calculateDataLengthInBytes();

    this->currentValueIntID = NUMBER_OF_BYTES_TO_INT_ID.at(
                                                this->currentValueByteSize);

    auto result = std::vector<uint8_t>(HEADER_SIZE_BYTES 
                + this->currentValueByteSize);

    this->fillContainerWithHeader(result);

    this->fillContainerWithData(result);

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
    uint8_t header = (INT_TYPE << TYPE_BIT_POS) 
                   | (this->currentValueIntID << INT_ID_BIT_POS);

    headerContainer[HEADER_POS] = header;

}

void UIntSerializer::fillContainerWithLength(std::vector<uint8_t>& lengthContainer)
{
    throw NotSupportedException();
}

void UIntSerializer::fillContainerWithData(std::vector<uint8_t>& dataContainer)
{

    uint64_t numOfByteToWrite = 0;

    while (numOfByteToWrite < this->currentValueByteSize)
    {
        auto shiftedVal = 
                this->currentlyProcessedValue >> (numOfByteToWrite * BYTE_SIZE);
        
        uint8_t chunkToWrite = static_cast<uint8_t>(0xFF & shiftedVal);

        dataContainer[HEADER_SIZE_BYTES + numOfByteToWrite] = chunkToWrite;

        numOfByteToWrite++;
    }
}