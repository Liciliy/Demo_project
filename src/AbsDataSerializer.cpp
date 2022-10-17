#include <AbsDataSerializer.hpp>

DataToSerialize::DataToSerialize(bool* boolPointer) : 
                                            boolToSerialize(boolPointer), 
                                            stringToSerialize(nullptr), 
                                            uIntToSerialize(nullptr), 
                                            intToSerialize(nullptr)
{};

DataToSerialize::DataToSerialize(std::string* strPointer) :
                                            boolToSerialize(nullptr), 
                                            stringToSerialize(strPointer), 
                                            uIntToSerialize(nullptr), 
                                            intToSerialize(nullptr)
{};

DataToSerialize::DataToSerialize(uint64_t* uintPointer) : 
                                            boolToSerialize(nullptr), 
                                            stringToSerialize(nullptr), 
                                            uIntToSerialize(uintPointer), 
                                            intToSerialize(nullptr)
{};
DataToSerialize::DataToSerialize(int64_t* intPointer) : 
                                            boolToSerialize(nullptr), 
                                            stringToSerialize(nullptr), 
                                            uIntToSerialize(nullptr), 
                                            intToSerialize(intPointer)
{};


bool* DataToSerialize::getBool() const
{
   return this->boolToSerialize;
}

std::string* DataToSerialize::getString() const
{
    return this->stringToSerialize;
}

uint64_t* DataToSerialize::getUint() const
{
    return this->uIntToSerialize;
}

int64_t* DataToSerialize::getInt() const
{
    return this->intToSerialize;
}


uint8_t AbsDataSerializer::calculateUintByteSize(const uint64_t& intToCalc)
{
    uint64_t result = UINT8_SIZE_IN_BYTES;

    if (intToCalc & UINT64_MASK)
    {
        result = UINT64_SIZE_IN_BYTES;
    }
    else if (intToCalc & UINT32_MASK)
    {
        result = UINT32_SIZE_IN_BYTES;
    }
    else if (intToCalc & UINT16_MASK)
    {
        result = UINT16_SIZE_IN_BYTES;
    }

    return result;
}
