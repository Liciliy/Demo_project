#ifndef INT_SERIALIZER
#define INT_SERIALIZER

#include "UIntSerializer.hpp"
#include <vector>
#include <cstdint>

// NOTE: This class could be a singleton.
class IntSerializer final : public UIntSerializer
{
public:
    std::vector<uint8_t> serialize(const DataToSerialize& dts);

private:
    int64_t signedCurrProcValue;

    void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) override;

};

#endif