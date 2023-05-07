#include "Header.h"
void Uzond::Users::print() const
{
       cout << MANIP << FullName->Name_property << " "
        << MANIP << FullName->Surname_property << " "
        << left << setw(8) << setfill(' ') << Year << " "
        << MANIP << piesel << " "
        << left << setw(8) << setfill(' ') << sex << " ";

}