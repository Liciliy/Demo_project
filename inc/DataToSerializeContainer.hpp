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
    DataToSerialize(const bool* boolValue);
    DataToSerialize(const std::string* strPointer);
    DataToSerialize(const uint64_t* uintPointer);
    DataToSerialize(const int64_t* intPointer);
    DataToSerialize() = delete;

    const bool* getBool() const;
    const std::string* getString() const; 
    const uint64_t* getUint() const;
    const int64_t* getInt() const;

private:
    const bool* boolToSerialize;
    const std::string* stringToSerialize;
    const uint64_t* uIntToSerialize;
    const int64_t* intToSerialize;
};