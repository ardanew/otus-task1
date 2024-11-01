#include <iostream>

#include "hello.h"
#include "version.h"

int main()
{
    std::cout << "Version: " << PATCH_NUM << std::endl;
    hello::greetings(std::cout);
    return 0;
}
