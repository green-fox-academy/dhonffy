#include "anagram.h"

bool testAnagram(std::string name, std::string anagram)
{
    if (name.length() != anagram.length()){
        return 0;
    }

    sort(name.begin(), name.end());
    sort(anagram.begin(), anagram.end());

    for (int i=0; i<name.length(); ++i)//hjkl
    {
        if (name.at(i) != anagram.at(i)){
            return 0;
        }
    }
    return 1;
}