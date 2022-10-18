#include "LinesReader.hpp"
#include <stdexcept>

#include <iostream>
LinesReader::LinesReader(const  char* pathToFile, 
                         std::shared_ptr<char[]> lineDataBuffer,
                         const uint64_t& lineReadBufferSize) 
    : maxLineSize (lineReadBufferSize), buffer(lineDataBuffer)
{
    this->fileStream = std::ifstream(pathToFile);

    if (!this->fileStream.good())
    {
        throw std::runtime_error("Error while opening JSON file!");
    }
}

bool LinesReader::hasData()
{
    bool result = false;
    if (this->fileStream)
        result =  true;

    return result;
}

uint64_t LinesReader::fillBufferWithNextLine()
{
    this->fileStream.getline(this->buffer.get(), this->maxLineSize);
    
    return this->fileStream.gcount();
}