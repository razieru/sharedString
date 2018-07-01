#include <iostream>
#include "sharedString.h"

int main()
{
    nsfw::sharedString str1("Hello World");
    nsfw::sharedString str2(", Dude!");
    std::cout << str1 + str2 << std::endl;

    return 0;
}
