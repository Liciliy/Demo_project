#ifndef NOT_SUPPORTED_EXCEPTION
#define NOT_SUPPORTED_EXCEPTION

#include <exception>


/**
 * @brief Used to prevent usage of inherited methods that are not intended be be
 *        implemented (hence, used) by children.
 * 
 */
class NotSupportedException : public std::exception {
public:
    char * what () {
        return (char*)"Method is not supported.";
    }
};


#endif