Exception
=========

A simple C++ Exception class.

> Note: To add a fully support of theses exceptions add the '-rdynamic' option to you linker settings on your finnal project.

------------------------------------------
> Note 2: Only libc friends/compilers can build this project. 'backtace' & 'backtrace_symbols' functions are defined by libc. 

##Using

    #include <iostream>
    #include <exception>
    #include "Exception.h"
    
    void bar(int i) {
        Exception * myE = new Exception("Your amazing message");
        throw e;
          // or
        throw new Exception("Your amazing message with priority", Warn);
          // or 
        throw new Exception("Your amazing message with an inner exception", e);
          // or
        throw new Exception("Your amazing message with an inner std exception", nex std::exception());
    }
    
    void foo() {
        bar(42);
    }
    
    int main(int argc, char** argv) {
        try {
           foo();
        }
        catch (Exception* e) {
            std::cout << "An Exception was throwed";
            
            if (e->getInnerException())
                std::cout << "with an inner exception:" << std::endl;
            else
                std::cout << ":" << std::endl;
            
            std::cout << e->getMessage() << std::endl << std::endl;
            
            for (int i = 0; i < e->getStackTrace().size(); i++)
                std::cout << "Stack Trace << i << ": " << e->getStackTrace[i] << std::endl;
            
            std::cout << std::endl;
            std::cout << "Thrower: " << e->getMethod() << std::endl;
            std::cout << "With criticity: " << e->getCriticity() << std::endl;
            
            // rethrow if needed
            if (e->getCriticity() > Warn)
                throw e;
        }
    
        return 0;
    }

And to compile it:
    gcc -rdynamic prog.cpp -o prog

The criticity have 5 level :
* Unknown (0)
* Info (1)
* Warn (2)
* Alert (3)
* Critical (4)

The returned value of the 'Exception::getInnerException()' method have for type 'void*'. Use 'typeof' to check the real type, 'Exception' or 'std::exception'.
