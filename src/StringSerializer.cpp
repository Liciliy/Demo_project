#include "StringSerializer.hpp"
#include "NotSupportedException.hpp"

std::vector<uint8_t> StringSerializer::serialize(const DataToSerialize& dts)
{
    if (dts.getString() == nullptr)
    {
        throw std::invalid_argument("Provided String pointer is a nullptr.");
    }

    this->currentlyProcessedValue = dts.getString();


    this->currentValueByteSize = calculateDataLengthInBytes();

    auto result = std::vector<uint8_t>(HEADER_SIZE_BYTES 
                + this->currentValueByteSize);

    this->fillContainerWithHeader(result);

    this->fillContainerWithData(result);

    return result;
}

uint64_t StringSerializer::calculateDataLengthInBytes()
{
    // NOTE: In theory, below static cast might result i ndata loss, but since 
    //       it's a test program - I've decided to leave with it :)
    return static_cast<uint64_t>(this->currentlyProcessedValue->length());
}

void StringSerializer::fillContainerWithHeader(std::vector<uint8_t>&  headerContainer)
{
    
    uint8_t header = (INT_TYPE << TYPE_BIT_POS) 
                   | (this->currentValueIntID << INT_ID_BIT_POS);

    headerContainer[HEADER_POS] = header;

}

void StringSerializer::fillContainerWithLength(std::vector<uint8_t>& lengthContainer)
{
    throw NotSupportedException();
}

void StringSerializer::fillContainerWithData(std::vector<uint8_t>& dataContainer)
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