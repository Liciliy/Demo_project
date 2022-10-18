#ifndef LINES_READER_CONTAINER
#define LINES_READER_CONTAINER

#include <fstream> 
#include <string>
#include <cstdio>
#include <memory>

/**
 * @brief Used to line by line read data from a file.
 * 
 */
class LinesReader
{
public:
    /**
     * @brief Construct a new Lines Reader object.
     * 
     * @param pathToFile Path to file to read from.
     * @param lineDataBuffer buffer into which the data is read.
     * @param lineReadBufferSize maximum number of characters to read at once.
     */
    LinesReader(const char* pathToFile, 
                std::shared_ptr<char[]> lineDataBuffer,
                const uint64_t& lineReadBufferSize);

    /**
     * @brief Fills buffer, used to construct the class, with data from file.   
     * 
     * @return uint64_t number of characters been read.
     */
    uint64_t fillBufferWithNextLine();

    /**
     * @brief Checks if there is more data to read.
     * 
     * @return true if there is more data to read.
     * @return false otherwise.
     */
    bool hasData();

private:
    bool dataAvailable;
    std::ifstream fileStream;
    std::shared_ptr<char[]> buffer;
    const uint64_t maxLineSize;
};

#endif