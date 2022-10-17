#include "StringSerializer.hpp"
#include "NotSupportedException.hpp"
#include "DataToSerializeContainer.hpp"


std::vector<uint8_t> StringSerializer::serialize(const DataToSerialize& dts)
{
    if (dts.getString() == nullptr)
    {
        throw std::invalid_argument("Provided String pointer is a nullptr.");
    }

    this->currentlyProcessedValue = dts.getString();

    this->currentStringByteSize = this->calculateDataLengthInBytes();

    // Below call calculates how many bytes are needed in the Length section to 
    // store numOfChars value. 
    // E.g. if there are 6 chars - it's enough to have Length section to be 1 
    // byte long. And if there are 300 chars - it is needed to have 2 bytes in
    // Length section - to store number 300.
    this->currentStringLengthByteSize = 
                      calculateUintByteSize(this->currentStringByteSize );

    if (this->currentStringLengthByteSize > STR_MAX_LENGTH_IN_BYTES)
    {
        throw std::out_of_range("Max string length in bytes exceeded.");
    }

    auto result = std::vector<uint8_t>(
                     HEADER_SIZE_BYTES                   // Header section.
                     + this->currentStringLengthByteSize // Length section.
                     + this->currentStringByteSize);     // Data section.

    this->fillContainerWithHeader(result);

    this->fillContainerWithLength(result);

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

    uint8_t header = 
        (STR_TYPE                          << TYPE_BIT_POS) 
      | (this->currentStringLengthByteSize << STR_LENGTH_SIZE_HEADER_BIT_POS);

    headerContainer[HEADER_POS] = header;

}
void StringSerializer::fillContainerWithLength(std::vector<uint8_t>& lengthContainer)
{
    // TODO this method is basically a copy of UInt...::fillContainerWithData.
    //      The methods could be somehow merged to avoid code duplication.
    uint64_t numOfByteToWrite = 0;

    while (numOfByteToWrite < this->currentStringLengthByteSize)
    {
        auto shiftedVal = 
                this->currentStringByteSize >> (numOfByteToWrite * BYTE_SIZE);
        
        uint8_t chunkToWrite = static_cast<uint8_t>(0xFF & shiftedVal);

        lengthContainer[HEADER_SIZE_BYTES + numOfByteToWrite] = chunkToWrite;

        numOfByteToWrite++;
    }
}

void StringSerializer::fillContainerWithData(std::vector<uint8_t>& dataContainer)
{
    uint16_t preFilledBytes = HEADER_SIZE_BYTES 
                            + this->currentStringLengthByteSize;


    uint64_t writtenBytes = 0;

    for(const char& c : *(this->currentlyProcessedValue)) 
    {
        dataContainer[preFilledBytes + writtenBytes] = c;
        writtenBytes++;
    }
}