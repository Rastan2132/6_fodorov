#include "Header.h"
void Uzond::Users::print(Uzond program, short j) const
{

    cout <<"   " << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " "
        << MANIP << FullName->Name_property << " "
        << MANIP << FullName->Surname_property << " "
        << left << setw(8) << setfill(' ') << Year << " "
        << MANIP << piesel << " "
        << left << setw(8) << setfill(' ') << sex << " ";

}