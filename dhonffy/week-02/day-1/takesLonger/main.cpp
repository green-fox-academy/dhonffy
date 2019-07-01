#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");

    // When saving this quote a disk error has occured. Please fix it.
    // Add "always takes longer than" to the quote between the words "It" and "you
    // using the replace function
    std::string toReplace("It you"); //toReplace stringnek értékadás
    size_t pos=quote.find(toReplace); //string hosszának meghatározása
    quote.replace(pos, toReplace.length(), "It always takes longer than you"); //(mit replacelek, eredeti hossza, mire))
    std::cout << quote << std::endl;
    return 0;
}