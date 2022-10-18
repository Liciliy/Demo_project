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

/**
 * @brief The struct is an opaque pointer implemented to avoid non-needed 
 *        includes in this hpp file. 
 */
struct HiddenImpl;

class KeysDictHandler;


/**
 * @brief Used to execute json records serialization.
 * 
 */
class RecsSerializationExecutor
{
public:
    /**
     * @brief Construct a new Recs Serialization Executor object. Stores a 
     *        pointer a an object with str keys to int IDs relations.    
     * 
     * @param recordKeysHandler 
     */
    RecsSerializationExecutor(std::shared_ptr<KeysDictHandler> recordKeysHandler);
    
    /**
     * @brief Serializes one json record (a number of key-value pairs) into 
     *        a byte structure.
     * 
     *        In addition, string key is replaced with an integer ID (in the 
     *        output deque). Relation between previous str keys and new int IDs
     *        is stored in this->hiddenImpl->keysDictHandler, provided at this 
     *        class construction.
     * 
     *        Output structure: deque: |vector_with_key_bytes|vector_with_value_bytes|NL_byte_vector|<sequence repeats>|
     * 
     * @param record json record to be serialized.
     * @return RecordAsBytes deque of vectors of bytes with output serialized 
     *         data.
     */
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