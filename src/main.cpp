#include <iostream>
//#include <headers/nlohmann/json.hpp>
#include "nlohmann/json.hpp"
#include <iomanip>
#include <bitset>

#include <fstream>

#include <cstdio>
#include <string>
#include "BoolSerializer.hpp"
#include "UIntSerializer.hpp"
#include "IntSerializer.hpp"
#include "StringSerializer.hpp"
#include "DataToSerializeContainer.hpp"
#include "NLConstructor.hpp"

using json = nlohmann::json;

struct InputLine
{
    char* startPtr;
    char* endPtr;
};


void fillHeader(std::vector<uint8_t> lol)
{
    
}

int main(int argc, char** argv)
{

    static constexpr uint8_t FILE_PATH_ARG_POS{0};
    if (argc < 2)
    {
        std::cout << "File path not provided! \nUsage:\n    jsonTranslator /path/to/input/file.txt" << std::endl;
        return 1;
    }
    std::cout << "Input path is: " << argv[FILE_PATH_ARG_POS] << std::endl;
 

    
    std::ifstream bigFile(argv[FILE_PATH_ARG_POS]);
    constexpr size_t bufferSize = 100 * 1024 * 1024;
    std::unique_ptr<char[]> buffer(new char[bufferSize]);
    while (bigFile)
    {
        bigFile.read(buffer.get(), bufferSize);
        // process data in buffer
    }


  
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
   
        if (el.value().type() == json::value_t::number_unsigned)
        {
            uint64_t unsignedVal;
            std::cout << "unsigned type;" << "\n";
            el.value().get_to(unsignedVal);

            std::cout << "unsigned type store: " << unsignedVal << "\n";

        }
    }

    std::cout << std::setw(4) << j << "\n\n";



    //uint8_t charVar   = 0xFF;
    //uint16_t shortVar = 0xFFFF;
    //uint32_t intVar   = 0xFFFFFFFF; //4294967295;
    //uint64_t longVar  = 0xFFFFFFFFFFFFFFFF;

    ////int64_t;

    //std::cout << "Char  " << typeid(charVar).name()  << "  " << charVar << std::endl;
    //std::cout << "Short " << typeid(shortVar).name() << "  " << shortVar << std::endl;
    //std::cout << "Int   " << typeid(intVar).name()   << "  " << intVar << std::endl;
    //std::cout << "Long  " << typeid(longVar).name()  << "  " << longVar << std::endl;


    //int16_t minusShort = -30000;


    //std::cout << "& result: " << (0x7FFF0000 & minusShort) << " Actual value: " << minusShort << std::endl;

    //char a = -58;
    //std::bitset<8> x(a);
    //std::cout << "-58 as bits " << x << '\n';
   // 
    //char aPos = 58;
    //std::bitset<8> xPos(aPos);
    //std::cout << " 58 as bits " << xPos << '\n';
   // 
    //short c = -315;
    //std::bitset<16> y(c);
    ////std::cout << "-315 as bits " << y << '\n';

    ////std::bitset<16> shortBits(c);
   // 
    //short posShort = 315;

    ////std::cout << "& short pos result: " << (0xFFFF & posShort) << " Actual value: " << posShort << std::endl;


    //char b = -123;
    //std::bitset<8> za(b);
    //std::cout << "-123 as bits " << za << '\n';
   // 
    //char bPos = 123;
    //std::bitset<8> zaPos(bPos);
    //std::cout << " 123 as bits " << zaPos << '\n';

    //std::cout << "& short pos result: " << (0b11111111 & abs(b)) << " Actual value: " << b << std::endl;

    //uint8_t tc = 0;

    //bool test_bool = true;
    //std::bitset<8> tc_bits(tc | (test_bool << 6));
    //std::cout << "Val: " << tc_bits << std::endl;


    //std::array<uint8_t, 5> test;

   // 

    //std::cout << sizeof(int64_t) << std::endl;
    //static constexpr uint16_t INT64_SIZE_IN_BYTES  {sizeof(int64_t)};

    //static constexpr uint16_t UINT64_SIZE_IN_BYTES = sizeof(uint64_t);

    
    //BoolSerializer bs = BoolSerializer();
    //auto testVal21 = true;    
    //auto res = bs.serialize(DataToSerialize(&testVal21));
    //for (const auto& val : res)    
    //{
    //    std::bitset<8> bit_repr(val);    
    //    std::cout << "Serialized bool: " << bit_repr << std::endl;
    //}
//
//
    //uint64_t ui64test = 12;
    //auto us = UIntSerializer();
    //auto res64 = us.serialize(DataToSerialize(&ui64test));
    //for (const auto& val :res64)
    //{
    //    std::bitset<8> bit_repr(val);
    //    std::cout << "Serialized Uint: " << bit_repr << std::endl;
    //}
//
    //int64_t i64test = -12;
    //auto is = IntSerializer();
    //auto ires64 = is.serialize(DataToSerialize(&i64test));
    //for (const auto& val :ires64)
    //{
    //    std::bitset<8> bit_repr(val);
    //    std::cout << "Serialized Int: " << bit_repr << std::endl;
    //}
//
    //std::string strTest = "Hello!q";
    //auto ss = StringSerializer();
    //auto sres = ss.serialize(DataToSerialize(&strTest));
    //for (const auto& val :sres)
    //{
    //    std::bitset<8> bit_repr(val);
    //    std::cout << "Serialized STR: " << bit_repr << std::endl;
    //}

    auto nlc = NLConstructor();

    auto nlb = nlc.constructNLByte();
    for (const auto& val :nlb)
    {
        std::bitset<8> bit_repr(val);
        std::cout << "Serialized NL: " << bit_repr << std::endl;
    }
}



