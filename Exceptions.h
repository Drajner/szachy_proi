#pragma once
#include <exception>

// !! BŁĄD: te funkcje tak de facto są noexcept
class OutsideBoardLoadException : public std::exception
{
    virtual const char* what() const noexcept
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

class CannotFindPiece : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Cannot find piece in chessboard";
    }
};