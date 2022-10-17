#include <iostream>
//#include <headers/nlohmann/json.hpp>
#include "nlohmann/json.hpp"
#include <iomanip>
#include <bitset>

#include <cstdio>
#include <string>
#include "BoolSerializer.hpp"
#include "UIntSerializer.hpp"
#include "IntSerializer.hpp"
#include "StringSerializer.hpp"
#include "DataToSerializeContainer.hpp"

using json = nlohmann::json;

struct InputLine
{
    char* startPtr;
    char* endPtr;
};


void fillHeader(std::vector<uint8_t> lol)
{
    
}


int main ()
{
    
    
    BoolSerializer bs = BoolSerializer();
    auto testVal21 = true;    
    auto res = bs.serialize(DataToSerialize(&testVal21));
    for (const auto& val : res)    
    {
        std::bitset<8> bit_repr(val);    
        std::cout << "Serialized bool: " << bit_repr << std::endl;
    }


    uint64_t ui64test = 12;
    auto us = UIntSerializer();
    auto res64 = us.serialize(DataToSerialize(&ui64test));
    for (const auto& val :res64)
    {
        std::bitset<8> bit_repr(val);
        std::cout << "Serialized Uint: " << bit_repr << std::endl;
    }

    int64_t i64test = -12;
    auto is = IntSerializer();
    auto ires64 = is.serialize(DataToSerialize(&i64test));
    for (const auto& val :ires64)
    {
        std::bitset<8> bit_repr(val);
        std::cout << "Serialized Int: " << bit_repr << std::endl;
    }

    std::string strTest = "Hello!q";
    auto ss = StringSerializer();
    auto sres = ss.serialize(DataToSerialize(&strTest));
    for (const auto& val :sres)
    {
        std::bitset<8> bit_repr(val);
        std::cout << "Serialized STR: " << bit_repr << std::endl;
    }
}



