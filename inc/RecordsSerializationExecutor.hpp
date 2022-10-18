#ifndef RECS_SERIALIZATION_EXECUTOR
#define RECS_SERIALIZATION_EXECUTOR

#include <deque>
#include <map>
#include <vector>

#include "nlohmann/json.hpp"


#include "AbsDataSerializer.hpp"


using json = nlohmann::json;
using TypeToSerializer = std::map<uint8_t, 
                                  std::unique_ptr<AbsDataSerializer>>;

using RecordAsBytes = std::deque<std::vector<uint8_t>>;
using TypeToProcessingLambda = std::map<uint8_t, 
                                        std::function<std::vector<uint8_t>(json)>>;

struct HiddenImpl;
class KeysDictHandler;



class RecsSerializationExecutor
{
public:
    RecsSerializationExecutor(std::shared_ptr<KeysDictHandler> recordKeysHandler);
    RecordAsBytes executeRecordSerialization(json record);
    ~RecsSerializationExecutor();
    
private:
    TypeToSerializer typeToSerializer;
    TypeToProcessingLambda typeToProcLambda;
    std::unique_ptr<HiddenImpl> hiddenImpl; 

    template<json::value_t E, typename T> 
    std::vector<uint8_t> getBytesToDump(nlohmann::json_abi_v3_11_2::json value)
    {
        T var;
        value.get_to(var);
        auto toSerialize = DataToSerialize(&var);
        auto bytes = this->typeToSerializer[static_cast<uint8_t>(E)]->serialize(toSerialize);
        return bytes;
    }


};



#endif