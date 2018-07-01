#include <iostream>
#include "sharedString.h"

int main()
{
    nsfw::sharedString str1("Hello World");
    nsfw::sharedString str2(", Dude!");
    std::cout << str1 + str2 << std::endl;

    str1[0] = 'Q';
    std::cout << str1[0] << std::endl;
    std::cout << str1 << std::endl;

//    char* ss1 = new char[50];
//    char* ss2 = new char[50];
//    ss1 = "Hello";
//    ss2 = "World";
//    ss1 = ss2;
//    ss2[2] = 'Z';
//    std::cout << ss2 << std::endl;
    return 0;
}
