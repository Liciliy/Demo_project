#include <AbsDataTranslator.hpp>

const std::map<uint64_t, char> AbsDataTranslator::NUMBER_OF_BYTES_TO_INT_ID =
{
    {UINT64_SIZE_IN_BYTES , INT64_ID},
    {INT64_SIZE_IN_BYTES  , INT64_ID},
    {UINT32_SIZE_IN_BYTES , INT32_ID},
    {INT32_SIZE_IN_BYTES  , INT32_ID},
    {UINT16_SIZE_IN_BYTES , INT16_ID},
    {INT16_SIZE_IN_BYTES  , INT16_ID},
    {UINT8_SIZE_IN_BYTES  , INT8_ID},
    {INT8_SIZE_IN_BYTES   , INT8_ID}

};