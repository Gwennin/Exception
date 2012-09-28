#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <vector>

#include "Enums.h"

class Exception
{
    public:
        Exception(std::string message, ExceptionCriticity criticity = Alert);
        Exception(std::string message, Exception* innerException);
        Exception(std::string message, std::exception* innerException);

        std::string getMessage();
        void* getInnerException();
        std::vector<std::string> getStackTrace();
        ExceptionCriticity getCriticity();
        std::string getMethod();

    protected:
        std::string _message;
        void* _innerException;
        std::vector<std::string> _stackTrace;
        ExceptionCriticity _criticity;
        std::string _method;

    private:
        Exception();

        void generateStackTrace();
        std::string findMethod();
};

#endif // EXCEPTION_H
