#pragma once

#include <iostream>
#include <exception>
#include <string>

class UnimplementedError: public std::exception {
    std::string msg;
    std::string file;
    int line;
public:
    UnimplementedError(std::string m, int l, std::string f);
    
    virtual ~UnimplementedError() noexcept;

    virtual const char* what() const noexcept;

    int _getErrorLineNumber() const noexcept;

    const char* _getErrorFilename() const noexcept;
};