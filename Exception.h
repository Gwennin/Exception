#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <vector>
#include <typeinfo>

#include "Enums.h"

namespace E {
    class Exception
    {
        public:
            Exception(std::string message, ExceptionCriticity criticity = Alert);
            Exception(std::string message, Exception* innerException);
            Exception(std::string message, std::exception* innerException);

            std::string getMessage();
            Exception* getInnerException();
            std::exception* getInnerStdException();
            std::vector<std::string> getStackTrace();
            ExceptionCriticity getCriticity();
            std::string getMethod();

        protected:
            std::string _message;
            Exception* _innerException;
            std::exception* _innerStdException;
            std::vector<std::string> _stackTrace;
            ExceptionCriticity _criticity;
            std::string _method;

        private:
            Exception();

            void generateStackTrace();
            std::string findMethod();
    };
}

#endif // EXCEPTION_H
