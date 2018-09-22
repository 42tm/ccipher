// require C++11 or newer version

#include "lib/atbash.hpp"
#include "lib/caesar.hpp"
#include "lib/vigenere.hpp"

#include <iostream>
#include <string>
using std::cout;

void printVersionInformation()
{
    // versioning
    cout << "Version : ";
    #ifdef _CCIPHER_VERSION
        cout << _CCIPHER_VERSION << ", ";
    #else
        cout << "(custom build)" << ", ";
    #endif

    // compiler attribution
    cout << "built with ";
    #ifdef __clang__
        std::cout << "LLVM Clang " << __clang_version__ << std::endl;
    #elif defined(__GNUC__)
        std::cout
            << "GNU C++ Compiler " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__;
        #ifdef defined(__MINGW64__)
            std::cout << " (MinGW-w64 64-bit)\n";
        #elif defined(__MINGW32__)
            std::cout << " (MinGW/MinGW-w64 32-bit)\n";
        #endif
    #elif defined(_MSC_VER)
        std::cout
            << "MS Visual C++ " << _MSC_FULL_VER << std::endl;
    #else
        std::cout << "unknown C++ compiler" << std::endl;
    #endif

    // compilation time
    #ifdef __GNUC__
        cout << "Compiled on " << __DATE__ << ", " << __TIME__ << endl;
    #endif
}

void printHelpInformation()
{
    
}

int main(int argc, char *argv[])
{
    if (argc == 1 || argv[1] == std::string("-h") || argv[1] == std::string("--help"))
    {
        cout << "ccipher - Encrypt text strings using classical ciphers.\n";
        printVersionInformation();
        printHelpInformation();
        return 0;
    }

}