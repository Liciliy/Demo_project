#ifndef UINT_SERIALIZER
#define UINT_SERIALIZER

#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>

/**
 * @brief Serializes one unsigned Int value to a vector of bytes using TVL-like 
 *        encoding.
 * 
 *        Logical output vector data struct:
 *         HEADER BYTE + DATA BYTES.
 * 
 *        Per byte output vector data structure: 
 *         BYTES_NUMBERS:  7 6   5   4    3   2   1   0 
 *         HEADER_BYTE:   |1|0|N/A|INT_SIZE|N/A|N/A|N/A|
 *         DATA_BYTES:    |Y|Y|YYY|YYY|YYYY|YYY|YYY|YYY| First data byte 
 *                                      ...
 *                        |Y|Y|YYY|YYY|YYYY|YYY|YYY|YYY| Last data byte 
 */
// NOTE: This class could be a singleton.
class UIntSerializer : public AbsDataSerializer
{
public:
    /**
     * @brief Performs serialization.
     * 
     * @param dts must contain UInt to serialize - e.g. must be initialized 
     *            using its UInt constructor. 
     * @return std::vector<uint8_t> with header and data bytes.
     */
    std::vector<uint8_t> serialize(const DataToSerialize& dts);

protected:
    uint64_t currentlyProcessedValue;
    uint64_t currentValueByteSize;
    uint8_t currentValueIntID;

    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;

};

#endif