#ifndef NL_CONSTRUCTOR
#define NL_CONSTRUCTOR
#include "AbsDataSerializer.hpp"
#include <vector>
#include <cstdint>

/**
 * @brief Constructs NL character as one byte.
 *        Constructed NL is intended to separate serialized JSON records.
 * 
 *        Logical output vector data struct:
 *         HEADER BYTE.
 * 
 *        Per byte output vector data structure: 
 *         BYTES_NUMBERS:  7 6   5   4   3   2   1   0 
 *         HEADER_BYTE:   |1|1|N/A|N/A|N/A|N/A|N/A|N/A|
 */
// NOTE: This class could be a singleton.
class NLConstructor final : private AbsDataSerializer
{
public:
    /**
     * @brief Performs construction.
     * 
     * @return std::vector<uint8_t> with one element - constructed NL byte.
     */
    std::vector<uint8_t> constructNLByte();


private:
    std::vector<uint8_t> serialize(const DataToSerialize& abc) override;

    uint64_t calculateDataLengthInBytes() override;
   
    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

    void fillContainerWithLength(std::vector<uint8_t>&  lengthContainer) override;

    void fillContainerWithData(std::vector<uint8_t>&  dataContainer) override;
};


#endif