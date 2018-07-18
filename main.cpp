#include <iostream>
#include "sharedString.h"
#include <cstring>

int main()
{
    nsfw::sharedString str1 = "Hello";
    nsfw::sharedString str2(str1);
    nsfw::sharedString str3 = str2;

    std::cout << str1[0] << std::endl;
    std::cout << str1 << " " << str2 << " " << str3 << std::endl;
    return 0;
}
