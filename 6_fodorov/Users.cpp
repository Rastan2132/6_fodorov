#include "Header.h"
void Uzond::Users::print() const
{
       cout << MANIP << FullName->Name_property << " "
        << MANIP << FullName->Surname_property << " "
        << left << setw(8) << setfill(' ') << Year << " "
        << MANIP << piesel << " "
        << left << setw(8) << setfill(' ') << sex << " ";

}

 void Uzond::Users::save(std::ostream& out) const
 {
     out << FullName->Name_property << " " << FullName->Surname_property << " "
         << Year << " " << piesel << " "
         << sex << " ";
 }

 void Uzond::Users::find(char* keyword) const {

   
         if (strstr_lower(stringToArrChar(FullName->Name_property).data(), keyword)
             || strstr_lower(stringToArrChar(FullName->Surname_property).data(), keyword)
             || strstr_lower(stringToArrChar(piesel).data(), keyword)
             || strstr_lower(stringToArrChar(Year).data(), keyword)
             || strstr_lower(stringToArrChar(sex).data(), keyword))

         {
             print_find(stringToArrChar(FullName->Name_property).data(), MAXLINE, keyword, MAXLINE, Red);
             print_find(stringToArrChar(FullName->Surname_property).data(), MAXLINE, keyword, MAXLINE, Red);
             print_find(stringToArrChar(Year).data(), MAXLINE, keyword, MAXLINE, Red);
             print_find(stringToArrChar(piesel).data(), MAXLINE, keyword, MAXLINE, Red);
             print_find(stringToArrChar(sex).data(), MAXLINE, keyword, MAXLINE, Red);

             cout << endl;
         }
     
 }