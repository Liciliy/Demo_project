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

std::string* DataToSerialize::getString()
{
    return this->stringToSerialize;
}

uint64_t* DataToSerialize::getUint()
{
    return this->uIntToSerialize;
}

int64_t* DataToSerialize::getInt()
{
    return this->intToSerialize;
}