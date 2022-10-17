#ifndef BOOL_SERIALIZER
#define BOOL_SERIALIZER
#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>

/**
 * @brief Serializes one Boolean value to a vector of one byte using TVL-like 
 *        encoding.
 * 
 *        Logical output vector data struct:
 *         HEADER BYTE.
 * 
 *        Per byte output vector data structure: 
 *         BYTES_NUMBERS:  7 6   5   4   3   2   1          0 
 *         HEADER_BYTE:   |0|0|N/A|N/A|N/A|N/A|N/A|BOOL_VALUE|
 */
// NOTE: This class could be a singleton.

class BoolSerializer final : public AbsDataSerializer
{
public:
    /**
     * @brief Performs serialization.
     * 
     * @param dts must contain bool to serialize - e.g. must be initialized 
     *            using its boolean constructor. 
     * @return std::vector<uint8_t> with one element - serialized boolean.
     */
    std::vector<uint8_t> serialize(const DataToSerialize& dts) override;

private:
    bool currentlyProcessedValue;
    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;
};


#endif