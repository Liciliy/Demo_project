#include "RecordsSerializationExecutor.hpp"

#include "BoolSerializer.hpp"
#include "UIntSerializer.hpp"
#include "IntSerializer.hpp"
#include "StringSerializer.hpp"
#include "DataToSerializeContainer.hpp"
#include "NLConstructor.hpp"

#include "KeysDictHandler.hpp"

static const json::value_t BOOL_JS_T {json::value_t::boolean};
static const json::value_t STR_JS_T  {json::value_t::string};
static const json::value_t UINT_JS_T {json::value_t::number_unsigned};
static const json::value_t INT_JS_T  {json::value_t::number_integer};

struct HiddenImpl{
    std::shared_ptr<KeysDictHandler> keysDictHandler;
    std::unique_ptr<NLConstructor> nlConstructor;

    HiddenImpl(std::shared_ptr<KeysDictHandler> keysDictHandler);
};

HiddenImpl::HiddenImpl(std::shared_ptr<KeysDictHandler> keysDictHandler) :
     keysDictHandler(keysDictHandler),
     nlConstructor(std::unique_ptr<NLConstructor>(new NLConstructor()))
{};

RecsSerializationExecutor::RecsSerializationExecutor(
    std::shared_ptr<KeysDictHandler> keysHandler) : 
        hiddenImpl(std::unique_ptr<HiddenImpl>(new HiddenImpl(keysHandler)))
{
    this->typeToSerializer[static_cast<uint8_t>(UINT_JS_T)] = 
                        std::unique_ptr<UIntSerializer>(new UIntSerializer());

    this->typeToSerializer[static_cast<uint8_t>(INT_JS_T)] = 
                        std::unique_ptr<IntSerializer>(new IntSerializer());

    this->typeToSerializer[static_cast<uint8_t>(BOOL_JS_T)] = 
                        std::unique_ptr<BoolSerializer>(new BoolSerializer());

    this->typeToSerializer[static_cast<uint8_t>(STR_JS_T)] = 
                        std::unique_ptr<StringSerializer>(new StringSerializer());
   
   
    this->typeToProcLambda[static_cast<uint8_t>(BOOL_JS_T)] = 
      [this](json value){ 
                            return this->getBytesToDump<BOOL_JS_T, bool>(value); 
                        };

    this->typeToProcLambda[static_cast<uint8_t>(STR_JS_T)] = 
      [this](json value){ 
                            return this->getBytesToDump<STR_JS_T, std::string>(value); 
                        };

    this->typeToProcLambda[static_cast<uint8_t>(UINT_JS_T)] = 
      [this](json value){ 
                            return this->getBytesToDump<UINT_JS_T, uint64_t>(value); 
                        };

    this->typeToProcLambda[static_cast<uint8_t>(INT_JS_T)] = 
      [this](json value){ 
                            return this->getBytesToDump<INT_JS_T, int64_t>(value); 
                        };
};

RecordAsBytes RecsSerializationExecutor::executeRecordSerialization(json record)
{
    RecordAsBytes result;
    for (const auto& el : record.items())
    {
      // === Storing str key, getting integer key, and serializing it === //
        auto uIntID = this->
                        hiddenImpl->
                            keysDictHandler->
                                storeKeyAndGetUintEquivalent(el.key());

        result.push_back(this->typeToSerializer[static_cast<uint8_t>(UINT_JS_T)]
                                  ->serialize(DataToSerialize(&uIntID)));
      // ================================================================ //

      // === Serializing value === //
        auto serializeFunc = 
                this->typeToProcLambda[static_cast<uint8_t>(el.value().type())];
        result.push_back(serializeFunc(el.value()));
      // ========================= //

    }

  // === Constructing NL character === //
    result.push_back(this->hiddenImpl->nlConstructor->constructNLByte());
  // ================================= //

    return result;
}

RecsSerializationExecutor::~RecsSerializationExecutor(){}
