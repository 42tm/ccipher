/*
 * vigenere - Library for the vigenere cypher
 * Copyright (C) 2018 42tm Team
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>
#include <cctype>
#include <stdexcept>

class vigenere 
{
    public:
    static std::string encrypt (std::string plaintext, std::string key);
    static std::string decrypt (std::string plaintext, std::string key);
    private:
    static void verify(std::string key);
    static int CharToInt (const char ch);
    static char IntToChar(const int i, bool isUpper = true);
    static char combine(char ch1, char ch2);
    static char divide(char ch1, char ch2);
};

void vigenere::verify(std::string key)
{
    for (const auto I : key)
        if (!isalpha(I))
            throw std::invalid_argument("Vigenere : key contains non-alphabetic character");
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
    try 
    {
        verify(key);
    }
    catch (std::exception &e)
    {
        throw e;
    }
    long k = 0;
    for (auto &itr : input)
        if (isalpha(itr))
            itr = combine(itr, key[(k++) % key.size()]);
    return input;
}

std::string vigenere::decrypt(std::string input, std::string key)
{
    try 
    {
        verify(key);
    }
    catch (std::exception &e)
    {
        throw e;
    }
    long k = 0;
    for (auto &itr : input)
        if (isalpha(itr))
            itr = divide(itr, key[(k++) % key.size()]);
    return input;
}