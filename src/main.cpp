#include <iostream>
#include "nlohmann/json.hpp"

#include <fstream>

#include <cstdio>
#include <string>

#include "KeysDictHandler.hpp"
#include "RecordsSerializationExecutor.hpp"
#include "LinesReader.hpp"

using json = nlohmann::json;

static const std::string KEYS_DICT_FILE_NAME{"keysDictFile"};
static const std::string RECORDS_OUTPUT_FILE_NAME{"recordsOutput"};


int main(int argc, char** argv)
{
    try
    {
    
    
    static constexpr uint8_t FILE_PATH_ARG_POS{1};
    static constexpr uint8_t LINE_LENGTH_ARG_POS{2};

  // === Reading of args could be implemented in a better way but since it's 
  //     test program and there is not much of the args - this should be good 
  //     enough.
    if (argc < 2)
    {
        std::cout << "File path not provided! \nUsage:\n    jsonTranslator /path/to/input/file.txt" << std::endl;
        return 1;
    }
    
    uint64_t lineToReadMaxSize {1024*1024};
    if (argc > 2)
    {
        lineToReadMaxSize = std::stoi(argv[LINE_LENGTH_ARG_POS]);
    }
  // =========================================================================


  // === Preparing input file read === //
    std::shared_ptr<char[]> lineBuffer(new char[lineToReadMaxSize]);

    LinesReader linesReader(argv[FILE_PATH_ARG_POS], 
                            lineBuffer,                             
                            lineToReadMaxSize);
  // ================================= //

  // === Preparing output file === //
    std::ofstream outputRecordsFile(RECORDS_OUTPUT_FILE_NAME, 
                                    std::ios::binary |std::ios::out);
    if (!outputRecordsFile.good())
    {
        throw std::runtime_error("Error while opening output records file!"); 
    }
  // ============================= //

    std::shared_ptr<KeysDictHandler> keysDictHandler {new KeysDictHandler()};
    RecsSerializationExecutor serializationExecutor(keysDictHandler);


    while (linesReader.hasData())
    {
      // === Reading next data line === //  
        auto numOfChars = linesReader.fillBufferWithNextLine();

        if (numOfChars == 0)
        {
            break;
        }
        char* lineStart = &lineBuffer.get()[0];
        char* lineEnd = &lineBuffer.get()[numOfChars];
      // ============================== //

      // === Parsing & serializing JSON === //
        json jsonRecord = json::parse(lineStart, lineEnd, nullptr, false);
        auto recordAsBytes = 
                serializationExecutor.executeRecordSerialization(jsonRecord);
      // ====================//

      // === Writing serialized record to the output file === // 
        for (const auto& vec : recordAsBytes )
        {
            outputRecordsFile.write((char*)&vec[0], 
                                    vec.size() * sizeof(uint8_t));
        }    
      // ==================================================== //
    }
 
    keysDictHandler->dumpKeysDictToFile(KEYS_DICT_FILE_NAME);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}



