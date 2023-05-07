#include "Header.h"

void Uzond::Children::print() const
{

    Users::print();
	COLOR p;
	p.back = 0;
	p.text = 2;
	SetColor(p);
    cout << MANIP << kindergarten;
	p.back = 0;
	p.text = 15;
	SetColor(p);

}


void Uzond::Children::save(std::ostream& out) const
{
	out << 0 << " ";
	Users::save(out);
	out << Kindergarten_property << " ";
}

void Uzond::Children::find(char* keyword) const {


    if (strstr_lower(stringToArrChar(FullName->Name_property).data(), keyword)
        || strstr_lower(stringToArrChar(FullName->Surname_property).data(), keyword)
        || strstr_lower(stringToArrChar(piesel).data(), keyword)
        || strstr_lower(stringToArrChar(Year).data(), keyword)
        || strstr_lower(stringToArrChar(sex).data(), keyword)
        || strstr_lower(stringToArrChar(kindergarten).data(), keyword))

    {
        print_find(stringToArrChar(FullName->Name_property).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(FullName->Surname_property).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(Year).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(piesel).data(), MAXLINE, keyword, MAXLINE, Red);
        print_find(stringToArrChar(sex).data(), MAXLINE, keyword, MAXLINE, Red);
        COLOR p;
        p.back = 0;
        p.text = 2;
        SetColor(p);
        print_find(stringToArrChar(kindergarten).data(), MAXLINE, keyword, MAXLINE, Red);
        p.back = 0;
        p.text = 15;
        SetColor(p);

        cout << endl;
    }

}