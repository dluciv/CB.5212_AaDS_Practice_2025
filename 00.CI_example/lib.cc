#include <iostream>
#include "lib.h"

const std::string who_am_i()
{
    return std::string("Олег");
}

void greet()
{
    std::cout << "Привет, " << who_am_i() << '!' << std::endl;
}
