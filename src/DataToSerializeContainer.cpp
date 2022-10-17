#include "DataToSerializeContainer.hpp"

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