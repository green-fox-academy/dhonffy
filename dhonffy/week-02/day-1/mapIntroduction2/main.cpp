#include <iostream>
#include <map>
#include <string>

int main()
{
//    Create a map where the keys are strings and the values are strings with the
//    following initial values
//    Key 	Value
//    978-1-60309-452-8 	A Letter to Jo
//    978-1-60309-459-7 	Lupus
//    978-1-60309-444-3 	Red Panda and Moon Bear
//    978-1-60309-461-0 	The Lab
    std::map<std::string,std::string> phoneNum = {
            {"978-1-60309-452-8", "A Letter to Jo>"},
            {"978-1-60309-459-7", "Lupus"},
            {"978-1-60309-444-3", "Red Panda and Moon Bear"},
            {"978-1-60309-461-0", "The Lab"}
    };
//    Print all the key-value pairs in the following format
//    A Letter to Jo (ISBN: 978-1-60309-452-8)
//    Lupus (ISBN: 978-1-60309-459-7)
//    Red Panda and Moon Bear (ISBN: 978-1-60309-444-3)
//    The Lab (ISBN: 978-1-60309-461-0)
    std::map<std::string,std::string>::iterator it = phoneNum.begin();
    for (it = phoneNum.begin(); it != phoneNum.end(); ++it) {
        std::cout << it->first
                  << ", "
                  << it->second
                  << std::endl;
    }
//    Remove the key-value pair with key 978-1-60309-444-3
    phoneNum.erase("978-1-60309-444-3");

//    Remove the key-value pair with value The Lab
    for (it = phoneNum.begin(); it != phoneNum.end(); ++it) {
        if (it->second == "The Lab") {
            phoneNum.erase(it->first);
        }
    }

//    Add the following key-value pairs to the map
//    Key 	Value
//    978-1-60309-450-4 	They Called Us Enemy
//    978-1-60309-453-5 	Why Did We Trust Him?
    phoneNum.insert(it, std::pair<std::string, std::string>("978-1-60309-450-4", "They Called Us Enemy"));
    phoneNum.insert(it, std::pair<std::string, std::string>("978-1-60309-453-5", "Why Did We Trust Him?"));
//    Print whether there is an associated value with key 478-0-61159-424-8 or not
    if (phoneNum.find("478-0-61159-424-8") != phoneNum.end()) {
        std::cout << "A value with the key 478-0-61159-424-8 is associated." << std::endl;
    } else std::cout << "A value with the key 478-0-61159-424-8 is not associated." << std::endl;
//    Print the value associated with key 978-1-60309-453-5
    std::cout << phoneNum["978-1-60309-453-5"] << std::endl;
    return 0;
}