#ifndef INT_SERIALIZER
#define INT_SERIALIZER

#include "UIntSerializer.hpp"
#include <vector>
#include <cstdint>

/**
 * @brief Serializes one signed Int value to a vector of bytes using TVL-like 
 *        encoding.
 * 
*        Logical output vector data struct:
 *        HEADER BYTE + DATA BYTES.
 * 
 *       Per byte output vector data structure: 
 *        BYTES_NUMBERS:  7 6    5   4    3   2   1   0 
 *        HEADER_BYTE:   |1|0|SIGN|INT_SIZE|N/A|N/A|N/A|
 *        DATA_BYTES:    |Y|Y|YYYY|YYY|YYYY|YYY|YYY|YYY| First data byte 
 *                                     ...
 *                       |Y|Y|YYYY|YYY|YYYY|YYY|YYY|YYY| Last data byte 
 * NOTE: After (possible) deserialization a positive integer will be treated as 
 *       an unsigned integer.
 */
// NOTE: This class could be a singleton.
class IntSerializer final : public UIntSerializer
{
public:
    /**
     * @brief Performs serialization.
     * 
     * @param dts must contain Int to serialize - e.g. must be initialized 
     *            using its Int constructor. 
     * @return std::vector<uint8_t> with header and data bytes.
     */
    std::vector<uint8_t> serialize(const DataToSerialize& dts);

private:
    int64_t signedCurrProcValue;

    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

};

#endif