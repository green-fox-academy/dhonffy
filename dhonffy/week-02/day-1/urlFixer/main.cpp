#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* args[])
{
    std::string url("https//www.reddit.com/r/nevertellmethebots");
    std::string toReplace("bots");
    size_t pos= url.find(toReplace);
    url.replace(pos, toReplace.length(), "odds");
    std::string toReplaceUrl("s//");
    size_t urlFault= url.find(toReplaceUrl);
    url.replace(urlFault, toReplaceUrl.length(), "s://");

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and
    // not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it
    // too!

    std::cout << url << std::endl;
    return 0;
}