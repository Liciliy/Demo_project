#include "IntSerializer.hpp"
#include "NotSupportedException.hpp"

std::vector<uint8_t> IntSerializer::serialize(const DataToSerialize& dts)
{
    if (dts.getInt() == nullptr)
    {
        throw std::invalid_argument("Provided Int pointer is a nullptr.");
    }

    this->signedCurrProcValue = *(dts.getInt());
    this->currentlyProcessedValue = abs(signedCurrProcValue);

    this->currentValueByteSize = calculateDataLengthInBytes();

    this->currentValueIntID = NUMBER_OF_BYTES_TO_INT_ID.at(
                                                this->currentValueByteSize);

    auto result = std::vector<uint8_t>(HEADER_SIZE_BYTES 
                + this->currentValueByteSize);

    this->fillContainerWithHeader(result);

    this->fillContainerWithData(result);

    return result;
}

void IntSerializer::fillContainerWithHeader(std::vector<uint8_t>&  headerContainer)
{
    UIntSerializer::fillContainerWithHeader(headerContainer);

    if (this->signedCurrProcValue < 0)
    {
        headerContainer[HEADER_POS] = headerContainer[HEADER_POS] 
                                    | (NEGATIVE_INT_SIGN_BIT << INT_SIGN_BIT_POS);
    }

}
