/* 
 * vigenere - Library for the vigenere cipher
 * Copyright (C) 2018 42tm Team
 */

#pragma once
#include <string>
#include <cctype>
#include <stdexcept>

class vigenere 
{
    public:
    static std::string encrypt (std::string plaintext, std::string key);
    static std::string decrypt (std::string plaintext, std::string key);
    private:
    static int CharToInt (const char ch);
    static char IntToChar(const int i, bool isUpper = true);
    static char combine(char ch1, char ch2);
    static char divide(char ch1, char ch2);
}

int vigenere::CharToInt(const char ch)
{
    if (ch >= 'A' && ch <= 'Z') return (ch - 'A');
    if (ch >= 'a' && ch <= 'z') return (ch - 'a');
    else return -1;
}

char vigenere::IntToChar(const int i, bool isUpper)
{
    if (i >= 0 && i < 26)
        return (isUpper ? (i + 'A') : (i + 'a'));
    else
        return 0;
}

char vigenere::combine(char ch1, char ch2)
{
    int ans = (CharToInt(ch1) + CharToInt(ch2)) % 26;
    return IntToChar(ans, isupper(ch1));
}

char vigenere::divide(char ch1, char ch2)
{
    int ans = CharToInt(ch1) - CharToInt(ch2);
    return IntToChar(ans < 0 ? ans + 26 : ans, isupper(ch1));
}

std::string vigenere::encrypt(std::string input, std::string key)
{
    long k = 0;
    for (auto &itr : input)
        if (isalpha(itr))
            itr = combine(itr, key[(k++) % key.size()]);
    return input;
}

std::string vigenere::decrypt(std::string input, std::string key)
{
    long k = 0;
    for (auto &itr : input)
        if (isalpha(itr))
            itr = divide(itr, key[(k++) % key.size()]);
    return input;
}