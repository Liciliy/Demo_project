#include <cstdint>
#include <string>

/**
 * @brief Used to provide serializers with values-to-serialize.
 *        The struct allows to implement unified interface shared between all 
 *        serializers.
 * 
 *        NOTE: This struct was not made as a template because otherwise the 
 *              serializers interfaces would need to specify value-to-serialize
 *              type which would force them to become (specialized) templates
 *              which eliminates need for this struct but complicates the 
 *              interfaces.
 */
struct DataToSerialize
{
    DataToSerialize(bool* boolValue);
    DataToSerialize(std::string* strPointer);
    DataToSerialize(uint64_t* uintPointer);
    DataToSerialize(int64_t* intPointer);
    DataToSerialize() = delete;

    bool* getBool() const;
    std::string* getString() const; 
    uint64_t* getUint() const;
    int64_t* getInt() const;

private:
    bool* boolToSerialize;
    std::string* stringToSerialize;
    uint64_t* uIntToSerialize;
    int64_t* intToSerialize;
};