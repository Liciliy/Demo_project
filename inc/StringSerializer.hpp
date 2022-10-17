#ifndef STRING_SERIALIZER
#define STRING_SERIALIZER
#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>
#include <string>

/**
 * @brief Serializes one signed String value to a vector of bytes using TVL-like 
 *        encoding.
 * 
 *        Logical output vector data struct:
 *         HEADER BYTE + STRING LENGTH BYTES + DATA BYTES.
 * 
 *        Per byte output vector data structure: 
 *         BYTES_NUMBERS:  7 6    5         4       3   2   1   0 
 *         HEADER_BYTE:   |0|1|SIZE_OF_LENGTH_SECTION|N/A|N/A|N/A|
 *         LENGTH_BYTES:  |X|X|XXXX|XXXXXXXXX|XXXXXXX|XXX|XXX|XXX| First length byte
 *                                      ...
 *                        |X|X|XXXX|XXXXXXXXX|XXXXXXX|XXX|XXX|XXX| Last length byte
 *         DATA_BYTES:    |Y|Y|YYYY|YYYYYYYYY|YYYYYYY|YYY|YYY|YYY| First data byte 
 *                                      ...
 *                        |Y|Y|YYYY|YYYYYYYYY|YYYYYYY|YYY|YYY|YYY| Last data byte 
 */
// NOTE: This class could be a singleton.
class StringSerializer final : public AbsDataSerializer
{
public:
    /**
     * @brief Performs serialization.
     * 
     * @param dts must contain String to serialize - e.g. must be initialized 
     *            using its String constructor. 
     * @return std::vector<uint8_t> with header, length, and data bytes.
     */
    std::vector<uint8_t> serialize(const DataToSerialize& dts);

protected:
    std::string* currentlyProcessedValue;
    uint64_t currentStringByteSize;
    
    // Below var defines how many bytes are need to store the processed string
    // length. Max expected value 8, as 8 bytes.
    uint8_t currentStringLengthByteSize; 

    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;

};

#endif