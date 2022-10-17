#ifndef ABS_DATA_TRANSLATOR
#define ABS_DATA_TRANSLATOR
#include<map>

class AbsDataTranslator
{

protected:
    static constexpr char BYTE_SIZE {8};

    static constexpr char TYPE_LENGTH_IN_BITS{2};
    static constexpr char TYPE_BIT_POS {6}; 
    static constexpr char BOOL_TYPE    {0b00};
    static constexpr char STR_TYPE     {0b01};
    static constexpr char INT_TYPE     {0b10};
    static constexpr char NEW_LINE_TYPE{0b11};
    
    static constexpr char HEADER_SIZE_BYTES{1};
    static constexpr char HEADER_POS {0};

    static constexpr char INT_ID_BIT_POS {3};
    static constexpr char INT8_ID  {0b00};
    static constexpr char INT16_ID {0b01};
    static constexpr char INT32_ID {0b10};
    static constexpr char INT64_ID {0b11};

    static constexpr uint64_t UINT64_MASK {0xFFFFFFFF00000000};
    static constexpr uint32_t UINT32_MASK {0xFFFF0000};
    static constexpr uint16_t UINT16_MASK {0xFF00};

    static constexpr uint16_t UINT64_SIZE_IN_BYTES {sizeof(uint64_t)};
    static constexpr uint16_t INT64_SIZE_IN_BYTES  {sizeof(int64_t)};
    static constexpr uint16_t UINT32_SIZE_IN_BYTES {sizeof(uint32_t)};
    static constexpr uint16_t INT32_SIZE_IN_BYTES  {sizeof(int32_t)};
    static constexpr uint16_t UINT16_SIZE_IN_BYTES {sizeof(uint16_t)};
    static constexpr uint16_t INT16_SIZE_IN_BYTES  {sizeof(int16_t)};
    static constexpr uint16_t UINT8_SIZE_IN_BYTES  {sizeof(uint8_t)};
    static constexpr uint16_t INT8_SIZE_IN_BYTES   {sizeof(int8_t)};

    static const std::map<uint64_t, char> NUMBER_OF_BYTES_TO_INT_ID;
};


#endif