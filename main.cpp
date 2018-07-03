#include <iostream>
#include "sharedString.h"
#include <cstring>

int main()
{
    nsfw::sharedString str1("Hello");
    nsfw::sharedString str2(str1);
    str1[0] = 'Z';
    std::cout << str1 << " " << str2 << std::endl;
    return 0;
}
