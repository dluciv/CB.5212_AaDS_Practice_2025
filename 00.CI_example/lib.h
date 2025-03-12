#ifndef  _LIB_H_
#define  _LIB_H_

#include <string>

const std::string who_am_i();
void greet();

class C
{
public:
    virtual void do_smth() = 0;
};

#endif //_LIB_H_
