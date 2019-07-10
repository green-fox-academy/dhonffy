#ifndef POSTIT_POSTIT_H
#define POSTIT_POSTIT_H
#include <string>

class PostIt
{
public:
    PostIt(std::string backgroundColor, std::string text, std::string textColor);
private:
    std::string _backgroungColor;
    std::string _text;
    std::string _textColor;
};


#endif //POSTIT_POSTIT_H
