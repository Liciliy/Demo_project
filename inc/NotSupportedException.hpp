#ifndef NOT_SUPPORTED_EXCEPTION
#define NOT_SUPPORTED_EXCEPTION

#include <exception>


class NotSupportedException : public std::exception {
public:
    char * what () {
        return (char*)"Method is not supported.";
    }
};


#endif