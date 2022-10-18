#ifndef KEYS_DICT_HANDLER
#define KEYS_DICT_HANDLER

#include <cstdio>
#include <string>
#include <unordered_map>
#include <mutex>


class KeysDictHandler
{
public:
    KeysDictHandler();
    uint64_t storeKeyAndGetUintEquivalent(const std::string& key);
    void dumpKeysDictToFile(const std::string& fileName);

private:
    std::unordered_map<std::string, uint64_t> keysDict;
    uint64_t numberOfKeys; 
    std::mutex accessMutex;
    inline uint64_t getNextFreeKeyUintId();
};


#endif