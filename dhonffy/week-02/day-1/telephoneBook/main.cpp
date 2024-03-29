#include <iostream>
#include <map>
#include <string>


//std::string jkmPhoneNumber();
int main()
{
//    We are going to represent our contacts in a map where the keys are going to be strings and the values are going to be strings as well.

//    Create a map with the following key-value pairs.
//    Name (key)        	Phone number (value)
//    William A. Lathan 	405-709-1865
//    John K. Miller 	    402-247-8568
//    Hortensia E. Foster 	606-481-6467
//    Amanda D. Newland 	319-243-5613
//    Brooke P. Askew 	    307-687-2982
    std::map<std::string, std::string> phoneBook  = {
            {"William A. Lathan", "405-709-1865"},
            {"John K. Miller", "402-247-8568"},
            {"Hortensia E. Foster", "606-481-6467"},
            {"Amanda D. Newland", "319-243-5613"},
            {"Brooke P. Askew", "307-687-2982"}
    };

//    Create an application which solves the following problems.
//    What is John K. Miller's phone number?
    std::cout << phoneBook["John K. Miller"] << std::endl;
//    Whose phone number is 307-687-2982?
    for (auto it = phoneBook.begin(); it != phoneBook.end() ; ++it) {
        if (it->second == "307-687-2982") {
            std::cout << it->first << std::endl;
        }
    }
//    Do we know Chris E. Myers' phone number?
    if (phoneBook.find("Chris E. Myers") != phoneBook.end()) {
        std::cout << "Yes." << std::endl;
    } else {
        std::cout << "No." << std::endl;
    }

    return 0;
}