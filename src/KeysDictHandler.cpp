#include <cstdio>
#include <fstream>
#include <stdexcept>

#include "KeysDictHandler.hpp"

#include "DataToSerializeContainer.hpp"
#include "StringSerializer.hpp"
#include "UIntSerializer.hpp"

KeysDictHandler::KeysDictHandler() : numberOfKeys(0)
{};

uint64_t KeysDictHandler::storeKeyAndGetUintEquivalent(const std::string& key)
{
    uint64_t result;

    const std::lock_guard<std::mutex> lock(this->accessMutex);
    {        
        auto keyIter = this->keysDict.find(key);
        if (keyIter != this->keysDict.end())
        {
            result = keyIter->second;
        }
        else
        {
            result = this->getNextFreeKeyUintId();
            keysDict[key] = result;
        }
    }
    return result;
}
inline uint64_t KeysDictHandler::getNextFreeKeyUintId()
{
    uint64_t result = this->numberOfKeys;
    this->numberOfKeys++;

    return result;
}

void KeysDictHandler::dumpKeysDictToFile(const std::string& fileName)
{
    const std::lock_guard<std::mutex> lock(this->accessMutex);
    {
        std::ofstream outputFile(fileName, std::ios::binary |std::ios::out);

        auto uIntSerializer = UIntSerializer();
        auto strSerializer = StringSerializer();

        if (!outputFile.good())
        {
            throw std::runtime_error("Error while dumping keys dict file!"); 
        }
        for (auto& keysIt : this->keysDict)
        { 
            // Dumping string key.
            auto strDataToSerialize = DataToSerialize(&keysIt.first);
            auto strBytes = strSerializer.serialize(strDataToSerialize);
            outputFile.write((char*)&strBytes[0], 
                             strBytes.size() * sizeof(uint8_t));

            // Dumping int ID.
            auto uIntDataToSerialize = DataToSerialize(&keysIt.second);
            auto uIntBytes = uIntSerializer.serialize(uIntDataToSerialize);
            outputFile.write((char*)&uIntBytes[0], 
                             uIntBytes.size() * sizeof(uint8_t));     
        }
    }
    
}