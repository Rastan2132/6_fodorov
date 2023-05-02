#pragma once
#include "Header.h"

/*
Uzond::Users::Users(const Users& other) {
    Name = other.Name;
    Surname = other.Surname;
    Year = other.Year;
    piesel = other.piesel;
    sex = other.sex;

*/
Uzond::Uzond()
{
    people = nullptr;
    Name = "";
    Numer = "";
    size_Of_arr_peopls = 0;
}

Uzond::Uzond(const Uzond& other) {
    Name = other.Name;
    Numer = other.Numer;
    size_Of_arr_peopls = other.size_Of_arr_peopls;
    if (size_Of_arr_peopls > 0) {
        people = new Users * [size_Of_arr_peopls];
        for (int i = 0; i < size_Of_arr_peopls; i++)
        {
            people[i] = new Users(*other.people[i]);
        }
    }
    else {
        people = nullptr;
    }
}
Uzond::~Uzond() {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
        people = nullptr;
    }
}
/*
void Uzond::setPeople(Users** people_) {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
    }
    size_Of_arr_peopls = size;
    if (size > 0) {
        people = new Users * [size];
        for (int i = 0; i < size; i++) {
            people[i] = new Users(*people_[i]);
        }
    }
    else {
        people = nullptr;
    }
}
*/
void Uzond::createPeopleArray(int size_of_people, vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork) {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
        people = nullptr;
    }
    size_Of_arr_peopls = size_of_people;
    if (size_of_people > 0) {
        people = new Users * [size_of_people];
        
        for (int i = 0; i < size_of_people; i++) {
            bool is_child = rand() % 2;
            string sex = rand_data(_sex);
            string name = arrOfNames[rand_data(sex)];
            string surname = arrOfSurnames[rand_data(sex)];
            string year = rand_data(_year);
            string piesel = rand_data(_piesel);
            if (is_child) {
                string Kindergarten = arrOfNameKindergarten[rand() % arrOfNameKindergarten.size()];
                people[i] = new Children(name, surname, year, piesel, sex, Kindergarten);
            }
            else {
                string Work = arrOfWork[rand() % arrOfWork.size()];
                people[i] = new People(name, surname, year, piesel, sex, Work, to_string(rand()% 20));
            }
           
        }
    }
}

/*
Uzond::Users* Uzond::getPerson(int index) const {
    if (index < 0 || index >= size_Of_arr_peopls) {
        return nullptr;
    }
    return people[index];
}
void Uzond::removeUzond(Uzond*& program, short index) {
    if (index < 0 || index >= size) {
        return;
    }
    Uzond* new_program = new Uzond[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i != index) {
            new_program[j] = program[i];
            j++;
        }
    }
    program = new_program;
}

void Uzond::removePerson(int index) {
    if (index < 0 || index >= size_Of_arr_peopls) {
        return;
    }
    Users** new_people = new Users * [size_Of_arr_peopls - 1];
    int j = 0;
    for (int i = 0; i < size_Of_arr_peopls; i++) {
        if (i != index) {
            new_people[j] = people[i];
            j++;
        }
        else {
            delete people[i];
        }
    }
    people = new_people;
}

void Uzond::addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames) {
    string sex = rand_data(sex_);
    string name = arrOfNames[rand_data(sex)];
    string surname = arrOfSurnames[rand_data(sex)];
    string year = rand_data(year_);
    string piesel = rand_data(piesel_);

    Users* person = new Users(name, surname, year, piesel, sex);
    Users** new_people = new Users * [size_Of_arr_peopls];
    new_people = people;
    new_people[size_Of_arr_peopls - 1] = person;
}
*/


/*
void Uzond::show_ones(Uzond program, int j)
{

    Uzond::Users* person = program.getPerson(j);
    if (person != nullptr) {
        cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " " << MANIP << person->Name << " " << MANIP << person->Surname << " " << MANIP << person->Year << " " << MANIP << person->piesel << " " << MANIP << person->sex << " ";
    }
    cout << endl << endl;
}

void Uzond::edit(int index_1, string name, string surname, string year, string piesel, string sex) {

    Users* person = new Users(name, surname, year, piesel, sex);
    Users** new_people = new Users * [size_Of_arr_peopls];
    for (int i = 0; i < size_Of_arr_peopls; i++) {
        new_people[i] = people[i];
    }
    new_people[index_1] = person;

    delete[] people;
    people = new_people;
}



void Uzond::sort(Uzond*& program)
{
    cout << endl << "Wybiesz:\n1 - posortowac za Name\n2 - posortowac za Surname\n3 - posortowac za sex\n4 - posortowac za piesel\n5 - posortowac za Year\nQ - Wyj\n";
    cout << endl;
    switch (_getch())
    {
    case '1':
        for (short l = 0; l < program->size_property; l++)
        {
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++) {
                for (short j = i + 1; j < program->size_Of_arr_peopls_property; j++) {
                    if (program[l].getPeople()[i]->Name.compare(program[l].getPeople()[j]->Name) > 0) {
                        swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
                        swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
                        swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
                        swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
                        swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
                    }
                }
            }
        }
        cout << endl << "Sorted" << endl;
        system("pause");
        break;
    case '2':
        for (short l = 0; l < program->size_property; l++)
        {
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++) {
                for (short j = i + 1; j < program->size_Of_arr_peopls_property; j++) {
                    if (program[l].getPeople()[i]->Surname.compare(program[l].getPeople()[j]->Surname) > 0) {
                        swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
                        swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
                        swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
                        swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
                        swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
                    }
                }
            }
        }
        cout << endl << "Sorted" << endl;
        system("pause");
        break;
    case '3':
        for (short l = 0; l < program->size_property; l++)
        {
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++) {
                for (short j = i + 1; j < program->size_Of_arr_peopls_property; j++) {
                    if (program[l].getPeople()[i]->sex.compare(program[l].getPeople()[j]->sex) > 0) {
                        swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
                        swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
                        swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
                        swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
                        swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
                    }
                }
            }
        }
        cout << endl << "Sorted" << endl;
        system("pause");
        break;
    case '4':
        for (short l = 0; l < program->size_property; l++)
        {
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++) {
                for (short j = i + 1; j < program->size_Of_arr_peopls_property; j++) {
                    if (program[l].getPeople()[i]->piesel.compare(program[l].getPeople()[j]->piesel) > 0) {
                        swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
                        swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
                        swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
                        swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
                        swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
                    }
                }
            }
        }
        cout << endl << "Sorted" << endl;
        system("pause");
        break;
    case '5':
        for (short l = 0; l < program->get_size(); l++)
        {
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++) {
                for (short j = i + 1; j < program->size_Of_arr_peopls_property; j++) {
                    if (program[l].getPeople()[i]->Year.compare(program[l].getPeople()[j]->Year) > 0) {
                        swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
                        swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
                        swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
                        swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
                        swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
                    }
                }
            }
        }
        cout << endl << "Sorted" << endl;
        system("pause");
        break;
    case 'q':
    case 'Q':
        break;
    default:
    {
        cout << endl << "Press 1, 2 or Q " << endl;
        system("pause");
    }
    }
}

void Uzond::find(Uzond*& program)
{
    if (program == nullptr || program->size_property == 0 || program->size_Of_arr_peopls_property == 0)
    {
        error();
        return;
    }
    char* keyword = new char[MAXLINE]; keyword[0] = '\0';

    COORD enter, hat;

    system("cls");
    cout << " Esc - Wejscie" << endl << endl;
    cout << "Szukaj: ";
    enter = getCursorPosition();

    cout << endl << " #   " stru << endl;
    hat = getCursorPosition();

    COORD temp_pos;
    short len = 0;

    do
    {
        //������ �������� ����� ��� ������.
        {
            int i = 0;
            do
            {
                if (!stredit(keyword, MAXLINE, enter.X, enter.Y, len, false)) return;
                len = (short)strlen(keyword);

                for (i = 0; i < len; i++)
                {
                    if (!(isdigit_r(keyword[i]) || isalpha_r(keyword[i]))) break;
                }

            } while (i != len || len == 0);
        }

        // ������� ����������. 

        setCursorPosition(hat.X, hat.Y);

        //������� ���������� ���������� ������.
        for (int i = 0; i < size; i++)
        {
            temp_pos = getCursorPosition();
            Clear(temp_pos.X, temp_pos.Y + i);
        }
        setCursorPosition(hat.X, hat.Y);
        system("cls");
        cout << " Esc - Wejscie" << endl << endl;
        cout << "Szukaj: ";
        enter = getCursorPosition();

        cout << endl << " #   " stru << endl;
        hat = getCursorPosition();
        //������� ����� ���������� ������
        for (short l = 0; l < size; l++)
        {
            cout << "Rezultat o " << l + 1 << " linii" << endl;
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++)
            {
                if (strstr_lower(stringToArrChar(program[l].getPeople()[i]->Name).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->Surname).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->piesel).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->Year).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->sex).data(), keyword))
                {
                    cout << left << setw(3) << i + 1 << "  ";
                    print_find(stringToArrChar(program[l].getPeople()[i]->Name).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->Surname).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->Year).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->piesel).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->sex).data(), MAXLINE, keyword, MAXLINE, Red);

                    cout << endl;
                }
            }
            cout << endl;
        }
    } while (true); //���� �� ������ Esc.

    delete[] keyword; keyword = nullptr;
}


bool Uzond::initForFile(Uzond*& program) {
    ifstream in("Uzonds.txt");
    if (!in.is_open()) {
        program->size_property = -1; // if error *size = -1;
        return false;
    }
    short size, size_of_peopl;
    in >> size >> size_of_peopl;


    Uzond* program_n = new Uzond[size];
    for (int i = 0; i < size; i++) {
        program_n[i].people = nullptr;
        string name_u, numer;
        in >> name_u >> numer;
        program_n[i].Name = name_u;
        program_n[i].Numer = numer;

        if (size_of_peopl > 0) {
            Users** people = new Users * [size_of_peopl];
            for (int j = 0; j < size_of_peopl; j++) {
                string name, surname, year, pesel, sex;
                in >> name >> surname >> year >> pesel >> sex;
                people[j] = new Users(name, surname, year, pesel, sex);
            }
            program_n[i].people = people;
        }
    }

    program = program_n;
    for (short i = 0; i < size; i++)
        program[i].size_property = size;
    for (short i = 0; i < size_of_peopl; i++)
        program[i].size_Of_arr_peopls_property = size_of_peopl;

    in.close();
    return true;
}


std::istream& operator>>(Uzond*& program, std::istream& in) {
    program->initForFile(program);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Uzond& program) {
    program.save(out);
    return out;
}
bool Uzond::save(std::ostream& out) const {
    out << size << " " << size_Of_arr_peopls << " ";

    for (short i = 0; i < size; i++) {
        out << Name << " " << Numer << " ";
        for (short j = 0; j < size_Of_arr_peopls; j++) {
            out << people[j]->Name << " " << people[j]->Surname << " "
                << people[j]->Year << " " << people[j]->piesel << " "
                << people[j]->sex << " ";
        }
        out << std::endl;
    }

    return true;
}
*/

void Uzond::show(Uzond* program) const
{
    system("cls");
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << MENU << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "					---=== UZOND BOOK ===--- your Uzond: " << program->size_property << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << stru << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";
    for (short i = 0; i < program->size_property; i++)
    {
        cout << right << setw(3) << setfill('0') << i + 1 << setfill(' ') << " ";
        cout << MANIP << program[i].Name_property << " " << MANIP << program[i].Numer_property << endl;
        cout << endl;
        for (short j = 0; j < program[i].size_Of_arr_peopls_property; j++)
        {

            people[j]->print(*this, j);
            cout << endl;
        }
        cout << endl << endl;
    }
}