#include "Header.h"
void Uzond::Users::print(Uzond program, short j) const
{
    cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " "
        << MANIP << FullName->Name_property << " "
        << MANIP << FullName->Surname_property << " "
        << MANIP << Year << " "
        << MANIP << piesel << " "
        << MANIP << sex << " ";

}