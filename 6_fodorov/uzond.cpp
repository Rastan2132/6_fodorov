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
            
            string piesel = rand_data(_piesel);
            if (is_child) {
                string Kindergarten = arrOfNameKindergarten[rand() % arrOfNameKindergarten.size()];
                people[i] = new Children(name, surname, to_string(2023 -(rand() % 18)), piesel, sex, Kindergarten);
            }
            else {
                string year = rand_data(_year);
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
}*/
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


void Uzond::addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork, bool flag) {
    string sex = rand_data(_sex);
    string name = arrOfNames[rand_data(sex)];
    string surname = arrOfSurnames[rand_data(sex)];
    string year = rand_data(_year);
    string piesel = rand_data(_piesel);
    Users* person = nullptr;
    if (flag) {

        string Kindergarten = arrOfNameKindergarten[rand() % arrOfNameKindergarten.size()];
         person = new Children(name, surname, to_string(2023 - (rand() % 18)), piesel, sex, Kindergarten);
    }
    else {
        string year = rand_data(_year);
        string Work = arrOfWork[rand() % arrOfWork.size()];
         person = new People(name, surname, year, piesel, sex, Work, to_string(rand() % 20));
    }
    Users** new_people = new Users * [size_Of_arr_peopls];
    for (int i = 0; i < size_Of_arr_peopls; i++) {
        new_people[i] = people[i];
    }
    new_people[size_Of_arr_peopls-1] = person;
    delete[] people;
    people = new_people;
}

Uzond::Users* Uzond::getPerson(int index) const {
    if (index < 0 || index >= size_Of_arr_peopls) {
        return nullptr;
    }
    return people[index];
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
                    if (program[l].getPeople()[i]->FullName->Name_property.compare(program[l].getPeople()[j]->FullName->Name_property) > 0) {
                        std::string temp_name = program[l].getPeople()[i]->FullName_property->Name_property;
                        program[l].getPeople()[i]->FullName_property->Name_property = program[l].getPeople()[j]->FullName->Name_property;
                        program[l].getPeople()[j]->FullName->Name_property = temp_name;

                        std::string temp_surname = program[l].getPeople()[i]->FullName->Surname_property;
                        program[l].getPeople()[i]->FullName->Surname_property = program[l].getPeople()[j]->FullName->Surname_property;
                        program[l].getPeople()[j]->FullName->Surname_property = temp_surname;

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
                    if (program[l].getPeople()[i]->FullName->Surname_property.compare(program[l].getPeople()[j]->FullName->Surname_property) > 0) {
                        std::string temp_name = program[l].getPeople()[i]->FullName_property->Name_property;
                        program[l].getPeople()[i]->FullName_property->Name_property = program[l].getPeople()[j]->FullName->Name_property;
                        program[l].getPeople()[j]->FullName->Name_property = temp_name;

                        std::string temp_surname = program[l].getPeople()[i]->FullName->Surname_property;
                        program[l].getPeople()[i]->FullName->Surname_property = program[l].getPeople()[j]->FullName->Surname_property;
                        program[l].getPeople()[j]->FullName->Surname_property = temp_surname;

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
                        std::string temp_name = program[l].getPeople()[i]->FullName_property->Name_property;
                        program[l].getPeople()[i]->FullName_property->Name_property = program[l].getPeople()[j]->FullName->Name_property;
                        program[l].getPeople()[j]->FullName->Name_property = temp_name;

                        std::string temp_surname = program[l].getPeople()[i]->FullName->Surname_property;
                        program[l].getPeople()[i]->FullName->Surname_property = program[l].getPeople()[j]->FullName->Surname_property;
                        program[l].getPeople()[j]->FullName->Surname_property = temp_surname;

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
                        std::string temp_name = program[l].getPeople()[i]->FullName_property->Name_property;
                        program[l].getPeople()[i]->FullName_property->Name_property = program[l].getPeople()[j]->FullName->Name_property;
                        program[l].getPeople()[j]->FullName->Name_property = temp_name;

                        std::string temp_surname = program[l].getPeople()[i]->FullName->Surname_property;
                        program[l].getPeople()[i]->FullName->Surname_property = program[l].getPeople()[j]->FullName->Surname_property;
                        program[l].getPeople()[j]->FullName->Surname_property = temp_surname;

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
                        std::string temp_name = program[l].getPeople()[i]->FullName_property->Name_property;
                        program[l].getPeople()[i]->FullName_property->Name_property = program[l].getPeople()[j]->FullName->Name_property;
                        program[l].getPeople()[j]->FullName->Name_property = temp_name;

                        std::string temp_surname = program[l].getPeople()[i]->FullName->Surname_property;
                        program[l].getPeople()[i]->FullName->Surname_property = program[l].getPeople()[j]->FullName->Surname_property;
                        program[l].getPeople()[j]->FullName->Surname_property = temp_surname;

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
        //Вводим ключевое слово для поиска.
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

        // Выводим результаты. 

        setCursorPosition(hat.X, hat.Y);

        //Очищаем предыдущие результаты поиска.
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
        //Выводим новые результаты поиска
        for (short l = 0; l < size; l++)
        {
            cout << "Rezultat o " << l + 1 << " linii" << endl;
            for (short i = 0; i < program->size_Of_arr_peopls_property; i++)
            {
                if (strstr_lower(stringToArrChar(program[l].getPeople()[i]->FullName->Name_property).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->FullName->Surname_property).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->piesel).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->Year).data(), keyword)
                    || strstr_lower(stringToArrChar(program[l].getPeople()[i]->sex).data(), keyword))
                {
                    cout << left << setw(3) << i + 1 << "  ";
                    print_find(stringToArrChar(program[l].getPeople()[i]->FullName->Name_property).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->FullName->Surname_property).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->Year).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->piesel).data(), MAXLINE, keyword, MAXLINE, Red);
                    print_find(stringToArrChar(program[l].getPeople()[i]->sex).data(), MAXLINE, keyword, MAXLINE, Red);

                    cout << endl;
                }
            }
            cout << endl;
        }
    } while (true); //Пока не нажата Esc.

    delete[] keyword; keyword = nullptr;
}


bool Uzond::initForFile(std::istream& in) {
   
        string name_u, numer;
        
        in >> name_u >> numer;
        Name = name_u;
        Numer = numer;
        int flag = 0;
        string name, surname, year, pesel, sex;
        if (size_Of_arr_peopls > 0) {
            Users** people_n = new Users * [size_Of_arr_peopls];
            for (int j = 0; j < size_Of_arr_peopls; j++) {
                in >> flag;
                if (flag ==0 ) {
                    string k;
                    in >>k >> name >> surname >> year >> pesel >> sex;
                    people_n[j] = new Children(name, surname, year, pesel, sex, k);
                }
                else{
                    string Work_property, Work_experience_property ;
                    in >> Work_property >> Work_experience_property >> name >> surname >> year >> pesel >> sex;
                    people_n[j] = new People(name, surname, year, pesel, sex, Work_property, Work_experience_property);
                }
               
            }
           people = people_n;
        }
    return true;
}


std::istream& operator>>(Uzond*& program, std::istream& in) {
    short size, size_of_peopl;
    in >> size >> size_of_peopl;
    program = new Uzond[size];
    for (int i = 0; i < size; i++) {
        program[i].size_property = size;
        program[i].size_Of_arr_peopls_property = size_of_peopl;
        program[i].initForFile(in);
    }
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

            if (dynamic_cast<Children*>(people[j])) {
                Children* children = dynamic_cast<Children*>(people[j]);
                out << 0 << " " << children->Kindergarten_property<<" ";
            }
            else if (dynamic_cast<People*>(people[j])) {
                People* people_ = dynamic_cast<People*>(people[j]);
                out << 1 << " " << people_->Work_property<<" "<< people_->Work_experience_property<<" ";
            }
            out << people[j]->FullName->Name_property << " " << people[j]->FullName->Surname_property << " "
                << people[j]->Year << " " << people[j]->piesel << " "
                << people[j]->sex << " ";
        }
        out << std::endl;
    }

    return true;
}


void show(Uzond* program) 
{
        system("cls");
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << MENU << endl;
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << "					---=== UZOND BOOK ===--- your Uzond: " << program->get_size() << endl;
        cout << "----------------------------------------------------------------------------------------------------\n";
        cout << stru << endl;
        cout << "----------------------------------------------------------------------------------------------------\n";
        for (short i = 0; i < program->get_size(); i++)
        {
            cout << right << setw(3) << setfill('0') << i + 1 << setfill(' ') << " ";
            cout << MANIP << program[i].getName() << " " << MANIP << program[i].getNumer() << endl;
            cout << endl ;
            for (short j = 0; j < program->get_size_Of_arr_peopls(); j++) {

                cout << " " << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " ";
                program[i].getPerson(j)->print();
                cout << endl;
            }
            cout << endl << endl;
        }
 
    cout << endl << endl;
}