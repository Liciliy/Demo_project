#ifndef KEYS_DICT_HANDLER
#define KEYS_DICT_HANDLER

#include <cstdio>
#include <string>
#include <unordered_map>
#include <mutex>

/**
 * @brief Used to store relation between string keys and int IDs.
 * 
 *        In addition, generates int IDs and allows to dump the relation to a file.  
 * 
 */
class KeysDictHandler
{
public:
    KeysDictHandler();
    /**
     * @brief Provides an int ID corresponding to a provided string key.
     *        If a string key was not previously stored - a new int ID is 
     *        created and the string key is stored.
     * 
     * @param key string key. 
     * @return uint64_t int ID corresponding to provided string key.
     */
    uint64_t storeKeyAndGetUintEquivalent(const std::string& key);

    /**
     * @brief Dumps stored string_key-to-int_ID relation to a file in a binary 
     *        format.
     * 
     * @param fileName 
     */
    void dumpKeysDictToFile(const std::string& fileName);

private:
    std::unordered_map<std::string, uint64_t> keysDict;
    uint64_t numberOfKeys; 
    std::mutex accessMutex;
    inline uint64_t getNextFreeKeyUintId();
};


#endif