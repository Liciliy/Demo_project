#ifndef ABS_DATA_SERIALIZER
#define ABS_DATA_SERIALIZER

#include "AbsDataTranslator.hpp"
#include <cstdint>
#include <vector>

struct DataToSerialize;

class AbsDataSerializer : protected AbsDataTranslator
{
public:
    /**
     * @brief Used to serialize a supported value into a vector of bytes.
     * 
     * @param dts struct with a value to serialize.
     * @return std::vector<uint8_t> vector with the serialized value.
     */
    virtual std::vector<uint8_t> serialize(const DataToSerialize& dts) = 0;

    /**
     * @brief Used to calculate minimum number of bytes needed to stor an 
     *        integer without loosing information.
     * 
     * @param intToCalc the integer for which the calculation is done.
     * @return uint8_t minimum number of bytes needed to store the integer.
     */
    static uint8_t calculateUintByteSize(const uint64_t& intToCalc);

protected:
    /**
     * @brief Used to calc how many bytes needed to store data-to-serialize.
     * 
     * @return uint64_t Length of data to serialize (in bytes).
     */
    virtual uint64_t calculateDataLengthInBytes() = 0;

    /**
     * @brief Fills result vector with a header data. 
     *        The header contains (at least):
     *          - Data type identifier
     *        Optionally, it contains:
     *          - Number of the following bytes that contain length of the data 
     *            to be stored.
     *          - Value - for boolean.
     * 
     * @param headerContainer result container filled with header.
     */
    virtual void fillContainerWithHeader(std::vector<uint8_t>& headerContainer) = 0;
    
    /**
     * @brief Filles container with value length data.  
     *        E.g. if the value size is 300 - there will be two length bytes 
     *        containing value 300.     
     * 
     * @param lengthContainer result container filled with length data.
     */
    virtual void fillContainerWithLength(std::vector<uint8_t>& lengthContainer) = 0;

    /**
     * @brief Files container with the value data - byte by byte.
     * 
     * @param dataContainer result container filled with value data.
     */
    virtual void fillContainerWithData(std::vector<uint8_t>& dataContainer) = 0;
};

#endif

