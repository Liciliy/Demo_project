#include <iostream>
//#include <headers/nlohmann/json.hpp>
#include "nlohmann/json.hpp"
#include <iomanip>
#include <bitset>

#include <cstdio>

#include "BoolSerializer.hpp"

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
    // a JSON text given an input with other values

    char array[] = "0{\"k\":9}8wqwr";

    char* begin_ptr = &array[1];
    char* end_ptr = &array[8];
    // parse and serialize JSON
    json j = json::parse(begin_ptr, end_ptr, nullptr, false);

    for (const auto& el : j.items())
    {

        decltype(el.value()) val_type = el.value();

        auto test = el.value().type();



        
        std::cout << el.key() << val_type << "  " << static_cast<int>(test) <<"  " << typeid(val_type).name() << std::endl; 
    }

    std::cout << std::setw(4) << j << "\n\n";



    uint8_t charVar   = 0xFF;
    uint16_t shortVar = 0xFFFF;
    uint32_t intVar   = 0xFFFFFFFF; //4294967295;
    uint64_t longVar  = 0xFFFFFFFFFFFFFFFF;

    //int64_t;

    std::cout << "Char  " << typeid(charVar).name()  << "  " << charVar << std::endl;
    std::cout << "Short " << typeid(shortVar).name() << "  " << shortVar << std::endl;
    std::cout << "Int   " << typeid(intVar).name()   << "  " << intVar << std::endl;
    std::cout << "Long  " << typeid(longVar).name()  << "  " << longVar << std::endl;


    int16_t minusShort = -30000;


    std::cout << "& result: " << (0x7FFF0000 & minusShort) << " Actual value: " << minusShort << std::endl;

    char a = -58;
    std::bitset<8> x(a);
    std::cout << "-58 as bits " << x << '\n';
    
    char aPos = 58;
    std::bitset<8> xPos(aPos);
    std::cout << " 58 as bits " << xPos << '\n';
    
    short c = -315;
    std::bitset<16> y(c);
    //std::cout << "-315 as bits " << y << '\n';

    //std::bitset<16> shortBits(c);
    
    short posShort = 315;

    //std::cout << "& short pos result: " << (0xFFFF & posShort) << " Actual value: " << posShort << std::endl;


    char b = -123;
    std::bitset<8> za(b);
    std::cout << "-123 as bits " << za << '\n';
    
    char bPos = 123;
    std::bitset<8> zaPos(bPos);
    std::cout << " 123 as bits " << zaPos << '\n';

    std::cout << "& short pos result: " << (0b11111111 & abs(b)) << " Actual value: " << b << std::endl;

    uint8_t tc = 0;

    bool test_bool = true;
    std::bitset<8> tc_bits(tc | (test_bool << 6));
    std::cout << "Val: " << tc_bits << std::endl;


    std::array<uint8_t, 5> test;

    

    std::cout << sizeof(int64_t) << std::endl;
    static constexpr uint16_t INT64_SIZE_IN_BYTES  {sizeof(int64_t)};

    static constexpr uint16_t UINT64_SIZE_IN_BYTES = sizeof(uint64_t);

    BoolSerializer bs = BoolSerializer();
    
    auto testVal21 = true;
    
    uint64_t testvalint = 12;
    auto res = bs.serialize(DataToSerialize(&testvalint));

    
    for (const auto& val : res)
    {
        std::bitset<8> bit_repr(val);
        std::cout << "Serialized bool: " << bit_repr << std::endl;
    }
}

