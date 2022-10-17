#ifndef ABS_DATA_SERIALIZER
#define ABS_DATA_SERIALIZER

#include "AbsDataTranslator.hpp"
#include <cstdint>
#include <vector>
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


class AbsDataSerializer : protected AbsDataTranslator
{
public:
    virtual std::vector<uint8_t> serialize(const DataToSerialize& dts) = 0;

protected:

    virtual uint64_t calculateDataLengthInBytes() = 0;

    virtual void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) = 0;

    virtual void fillContainerWithLength(std::vector<uint8_t>& lengthContainer) = 0;

    virtual void fillContainerWithData(std::vector<uint8_t>& dataContainer) = 0;
};

#endif

