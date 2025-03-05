#include <iostream>
#include "lib.h"

const std::string who_am_i()
{
    return std::string("Олег");
}

void greet(std::ostream &ost)
{
    ost << "Привет, " << who_am_i() << '!' << std::endl;
}

void writesmth(std::ostream &ost)
{
    ost.write("Что-то...\n", 15);
    ost.flush();
}
