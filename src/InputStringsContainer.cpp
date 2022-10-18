#include "InputStringsContainer.hpp"
#include <stdexcept>

/////////////////////////////////////////
// THIS FILE IS FOR POSSIBLE FUTURE USE//
/////////////////////////////////////////

InputLine::InputLine(char* beginPtr, 
                     char* endPtr/* , 
                     bool isValid*/ ) : lineBeginPtr(beginPtr), 
                                     lineEndptr(endPtr)/* , 
                                     isObjectValid(isValid) */
{};

//void InputLine::invalidatePointers()
//{
//    this->isObjectValid = true; 
//}

const char* InputLine::begin() const
{
    //this->checkPointerForValidity();
    return this->lineBeginPtr;
}

const char* InputLine::end() const
{
    //this->checkPointerForValidity();
    return this->lineEndptr;
}

//inline void InputLine::checkPointerForValidity() const
//{
//    if (this->isObjectValid)
//    {
//        throw std::runtime_error("Input line pointers are invalid!");
//    }
//}