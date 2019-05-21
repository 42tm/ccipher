// require C++11 or newer version
#include "lib/atbash.cpp"
#include "lib/caesar.cpp"
#include "lib/vigenere.cpp"

#include <iostream>
#include <string>
#include <unordered_set>
#include <stdexcept>
using std::cout;

std::unordered_set <std::string> ciphers;

void printVersionInformation();
void printHelpInformation();
void initializeResources();

int main(int argc, char *argv[])
{
    initializeResources();
    if (argc == 1 || argv[1] == std::string("-h") || argv[1] == std::string("--help"))
    {
        cout << "ccipher - Encrypt text strings using classical ciphers.\n";
        printVersionInformation();
        printHelpInformation();
        return 0;
    }
    std::string cipher (argv[1]);
    std::string command (argv[2]);
    std::string plaintext (argv[3]);
    if (cipher == "atbash")
        return cout << atbash(plaintext), 0;
    if (cipher == "rot13")
        return cout << rot13(plaintext), 0;
    if (cipher == "caesar")
    {
        int shift;
        try 
        {
            shift = std::stoi(std::string(argv[4])) % 26;
            if (command == "d") shift = 26 - shift;
        }
        catch (std::exception e)
        {
            return std::cerr << "Caesar cipher : Invalid shift value encountered.\n", 1;
        }
        return cout << caesar(plaintext, shift), 0;
    }
    if (cipher == "vigenere")
    {
        try 
        {
            if (command == "d") return cout << vigenere::decrypt(plaintext, std::string(argv[4])), 0;
            else return cout << vigenere::encrypt(plaintext, std::string(argv[4])), 0;
        }
        catch (std::exception &e)
        {
            return std::cerr << "Vigènere : key contains non-alphabetic character" << std::endl, 1;
        }
    }
}

void printVersionInformation()
{
    using std::cout;
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
        std::cout << "LLVM Clang++ " << __clang_version__ << std::endl;
    #elif defined(__GNUC__)
        std::cout
            << "GNU C++ Compiler " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__;
        #if defined(__MINGW64__)
            std::cout << " (MinGW-w64 64-bit)\n";
        #elif defined(__MINGW32__)
            std::cout << " (MinGW/MinGW-w64 32-bit)\n";
        #else
            std::cout << '\n';
        #endif
    #elif defined(_MSC_VER)
        std::cout
            << "MS Visual C++ " << _MSC_FULL_VER << std::endl;
    #else
        std::cout << "unknown C++ compiler" << std::endl;
    #endif

    // compilation time
    #ifdef __GNUC__
        cout << "Compiled on " << __DATE__ << ", " << __TIME__ << std::endl;
    #endif
}

void printHelpInformation()
{
    using std::cout;
    std::cout   << "ccipher help : ccipher <cipher> <e|d> [args]\n";
    std::cout   << "\te means encrypt. d means decrypt.\n";
    std::cout   << "Possible values for <cipher> :\n"
                << "\tatbash - Atbash cipher. Arguments passed : [text]\n"
                << "\trot13 - ROT13 cipher. Arguments passed : [text]\n"
                << "\tcaesar - Caesar cipher. Arguments passed : [text] [shift]\n"
                << "\tvigenere - Vigènere cipher. Arguments passed : [text] [key]\n";
}

void initializeResources()
{
    ciphers.insert("atbash");
    ciphers.insert("vigenere");
    ciphers.insert("caesar");
    ciphers.insert("rot13");
}
