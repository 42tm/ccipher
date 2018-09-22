#pragma once
#include <string>
std::string caesar (std::string plaintext, int shift = 13)
{
    for (char &I : plaintext)
        if (isupper(I))
            I = (I + shift - 'A') % 26 + 'A';
        else
            if (islower(I))
                I = (I + shift - 'a') % 26 + 'a';
    return plaintext;
}

std::string rot13 (std::string plaintext)
{
    return caesar(plaintext);
}
