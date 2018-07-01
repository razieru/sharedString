#include <iostream>
#include "sharedString.h"

int main()
{
    nsfw::sharedString str1("Hello World");
    std::cin >> str1;
    std::cout << str1 << std::endl;

    return 0;
}
