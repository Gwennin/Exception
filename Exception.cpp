#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <exception>

#include "Exception.h"

using namespace E;

Exception::Exception() {}

Exception::Exception(std::string message, ExceptionCriticity criticity)
{
    _message = message;
    _criticity = criticity;
    _innerException = 0;
    _innerStdException = 0;

    this->generateStackTrace();
    _method = this->findMethod();
}

Exception::Exception(std::string message, Exception* innerException) {
    _message = message;
    _innerException = innerException;
    _innerStdException = 0;
    if (innerException)
        _criticity = innerException->getCriticity();
    else
        _criticity = Alert;

    this->generateStackTrace();
    _method = this->findMethod();
}

Exception::Exception(std::string message, std::exception* innerException) {
    _message = message;
    _innerException = 0;
    _innerStdException = innerException;
    _criticity = Alert;

    this->generateStackTrace();
    _method = this->findMethod();
}

std::string Exception::getMessage() {
    return _message;
}

Exception* Exception::getInnerException() {
    return _innerException;
}

std::exception* Exception::getInnerStdException() {
    return _innerStdException;
}

std::vector<std::string> Exception::getStackTrace() {
    return _stackTrace;
}

void Exception::generateStackTrace() {
    void *buff[12];
    size_t size;
    char **symbols;

    size = backtrace (buff, 12);
    symbols = backtrace_symbols (buff, size);

    for (unsigned int i = 2; i < size; i++) {
        _stackTrace.push_back(symbols[i]);
    }

    free (symbols);
}

ExceptionCriticity Exception::getCriticity() {
    return _criticity;
}

std::string Exception::getMethod() {
    return _method;
}

std::string Exception::findMethod() {
    if (_stackTrace.empty()) {
        this->generateStackTrace();
    }
    return _stackTrace.front();
}
