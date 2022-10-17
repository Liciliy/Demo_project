#include "NLConstructor.hpp"
#include "NotSupportedException.hpp"
#include "DataToSerializeContainer.hpp"

std::vector<uint8_t> NLConstructor::serialize(const DataToSerialize& abc)
{
    throw NotSupportedException();
}

uint64_t NLConstructor::calculateDataLengthInBytes()
{
    throw NotSupportedException();
}

void NLConstructor::fillContainerWithHeader(std::vector<uint8_t>&  headerContainer)
{
    uint8_t header = NEW_LINE_TYPE << TYPE_BIT_POS;

    headerContainer[HEADER_POS] = header;
}

void NLConstructor::fillContainerWithLength(std::vector<uint8_t>& lengthContainer)
{
    throw NotSupportedException();
}

void NLConstructor::fillContainerWithData(std::vector<uint8_t>& dataContainer)
{
    throw NotSupportedException();
}

std::vector<uint8_t> NLConstructor::constructNLByte()
{
    auto result = std::vector<uint8_t>(HEADER_SIZE_BYTES);
    this->fillContainerWithHeader(result);

    return result;
}