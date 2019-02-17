#include <iostream>
#include <exception>

#include "UnimplementedError.h"

UnimplementedError::UnimplementedError(std::string m, int l, std::string f):
    msg(m), file(f), line(l) {
        msg = "inherited class function unimplemented: \nspecified msg: " + msg;
        msg += "\nerror file: " + file + 
                "\nerror line number: " + std::to_string(line);
    };

UnimplementedError::~UnimplementedError() noexcept {};

const char* UnimplementedError::what() const noexcept {
    return msg.c_str() ;
}

int UnimplementedError::_getErrorLineNumber() const noexcept {
    return line;
}

const char* UnimplementedError::_getErrorFilename() const noexcept {
    return file.c_str();
}