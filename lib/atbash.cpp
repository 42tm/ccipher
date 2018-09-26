
#include <string>
#include <cctype>

std::string atbash (std::string in) 
{   
    for (std::size_t a = 0 ; a < in.size() ; a++)
        if (isalpha(in[a]))
            if (isupper(in[a]))
                in[a] = 25 + ('A' << 1) - (in[a]);
            else
                in[a] = 25 + ('a' << 1) - (in[a]);
    return in;
}