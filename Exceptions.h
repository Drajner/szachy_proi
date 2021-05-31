#pragma once
#include <exception>

class OutsideBoardLoadException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Tried to load an invalid position";
    }
};

class OutsideBoardWriteException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Tried to output an invalid position";
    }
};