#include "DataToSerializeContainer.hpp"
DataToSerialize::DataToSerialize(const bool* boolPointer) : 
                                            boolToSerialize(boolPointer), 
                                            stringToSerialize(nullptr), 
                                            uIntToSerialize(nullptr), 
                                            intToSerialize(nullptr)
{};

DataToSerialize::DataToSerialize(const std::string* strPointer) :
                                            boolToSerialize(nullptr), 
                                            stringToSerialize(strPointer), 
                                            uIntToSerialize(nullptr), 
                                            intToSerialize(nullptr)
{};

DataToSerialize::DataToSerialize(const uint64_t* uintPointer) : 
                                            boolToSerialize(nullptr), 
                                            stringToSerialize(nullptr), 
                                            uIntToSerialize(uintPointer), 
                                            intToSerialize(nullptr)
{};
DataToSerialize::DataToSerialize(const int64_t* intPointer) : 
                                            boolToSerialize(nullptr), 
                                            stringToSerialize(nullptr), 
                                            uIntToSerialize(nullptr), 
                                            intToSerialize(intPointer)
{};


const bool* DataToSerialize::getBool() const
{
    return this->boolToSerialize;
}

const std::string* DataToSerialize::getString() const
{   
    return this->stringToSerialize;
}

const uint64_t* DataToSerialize::getUint() const
{
    return this->uIntToSerialize;
}

const int64_t* DataToSerialize::getInt() const
{
    return this->intToSerialize;
}