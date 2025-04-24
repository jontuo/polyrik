
#ifndef __EXCEPTION_HPP_INCLUDED__
#define __EXCEPTION_HPP_INCLUDED__

#include <string>



class Exception: public std::exception
{
    public:
        Exception(std::string reason);
        const char* getReason() const;
    private:
        std::string reason;
};

#endif
