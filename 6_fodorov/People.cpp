#include "Header.h"


void Uzond::People::print(Uzond program, short j) const
{
    Users::print(program, j);
    COLOR p;
    p.back = 0;
    p.text = 4;
    SetColor(p);
    cout << MANIP << work << " "
        << MANIP << work_experience ;
    p.back = 0;
    p.text = 15;
    SetColor(p);

}