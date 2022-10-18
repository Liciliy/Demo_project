#ifndef INPUT_STRINGS_CONTAINER
#define INPUT_STRINGS_CONTAINER
/////////////////////////////////////////
// THIS FILE IS FOR POSSIBLE FUTURE USE//
/////////////////////////////////////////

#include "LinesReader.hpp"

struct InputLine
{
public:
    InputLine(char* beginPtr, char* endPtr/* , bool isValid */);
    const char* begin() const;
    const char* end() const;

private:
    char* lineBeginPtr;
    char* lineEndptr;
    //bool isObjectValid;

    //void invalidatePointers();
    //inline void checkPointerForValidity() const;

    //friend class LinesReader;
};


#endif