#include "Header.h"


void Uzond::People::print() const
{
    Users::print();
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

void Uzond::People::save(std::ostream& out) const
{
    out << 1 << " ";
    Users::save(out);
    out<<Work_property << " " << Work_experience_property << " ";
}

void Uzond::People::find(char* keyword) const {


    if (strstr_lower(stringToArrChar(FullName->Name_property).data(), keyword)
        || strstr_lower(stringToArrChar(FullName->Surname_property).data(), keyword)
        || strstr_lower(stringToArrChar(piesel).data(), keyword)
        || strstr_lower(stringToArrChar(Year).data(), keyword)
        || strstr_lower(stringToArrChar(sex).data(), keyword)
        || strstr_lower(stringToArrChar(work).data(), keyword)
        || strstr_lower(stringToArrChar(work_experience).data(), keyword))

    {
        print_find(stringToArrChar(FullName->Name_property).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(FullName->Surname_property).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(Year).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(piesel).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(sex).data(), MAXLINE, keyword, MAXLINE, Red);
        COLOR p;
        p.back = 0;
        p.text = 9;
        SetColor(p);
        print_find(stringToArrChar(work).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(work_experience).data(), MAXLINE, keyword, MAXLINE, Red);
        p.back = 0;
        p.text = 15;
        SetColor(p);

        cout << endl;
    }

}