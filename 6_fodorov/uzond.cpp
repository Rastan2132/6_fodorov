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
void Uzond::createPeopleArray(vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork) {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            delete people[i];
        }
        delete[] people;
        people = nullptr;
    }
    if (size_Of_arr_peopls > 0) {
        people = new Users * [size_Of_arr_peopls];
        
        for (int i = 0; i < size_Of_arr_peopls; i++) {
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
void removeUzond(Uzond*& program, short index) {
    if (index < 0 || index >= program->size_property) {
        return;
    }
    Uzond* new_program = new Uzond[program->size_property - 1];
    int j = 0;
    for (int i = 0; i < program->size_property; i++) {
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





void Uzond::sort(short flag)
{

    switch (flag)
    {
    case 1:
        for (short i = 0; i < size_Of_arr_peopls; i++) {
            for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                if (people[i]->FullName->Name_property.compare(people[j]->FullName->Name_property) > 0) {
                    std::string temp_name = people[i]->FullName_property->Name_property;
                    people[i]->FullName_property->Name_property = people[j]->FullName->Name_property;
                    people[j]->FullName->Name_property = temp_name;

                    std::string temp_surname = people[i]->FullName->Surname_property;
                    people[i]->FullName->Surname_property = people[j]->FullName->Surname_property;
                    people[j]->FullName->Surname_property = temp_surname;
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 2:
        for (short i = 0; i < size_Of_arr_peopls; i++) {
            for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                if (people[i]->FullName->Surname_property.compare(people[j]->FullName->Surname_property) > 0) {
                    std::string temp_name = people[i]->FullName_property->Name_property;
                    people[i]->FullName_property->Name_property = people[j]->FullName->Name_property;
                    people[j]->FullName->Name_property = temp_name;

                    std::string temp_surname = people[i]->FullName->Surname_property;
                    people[i]->FullName->Surname_property = people[j]->FullName->Surname_property;
                    people[j]->FullName->Surname_property = temp_surname;
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }

        break;
    case 3:
        for (short i = 0; i < size_Of_arr_peopls; i++) {
            for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                if (people[i]->sex.compare(people[j]->sex) > 0) {
                    std::string temp_name = people[i]->FullName_property->Name_property;
                    people[i]->FullName_property->Name_property = people[j]->FullName->Name_property;
                    people[j]->FullName->Name_property = temp_name;

                    std::string temp_surname = people[i]->FullName->Surname_property;
                    people[i]->FullName->Surname_property = people[j]->FullName->Surname_property;
                    people[j]->FullName->Surname_property = temp_surname;
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 4:
        for (short i = 0; i < size_Of_arr_peopls; i++)
        {
            for (short j = i + 1; j < size_Of_arr_peopls; j++)
            {
                if (people[i]->piesel.compare(people[j]->piesel) > 0)
                {
                    std::string temp_name = people[i]->FullName_property->Name_property;
                    people[i]->FullName_property->Name_property = people[j]->FullName->Name_property;
                    people[j]->FullName->Name_property = temp_name;

                    std::string temp_surname = people[i]->FullName->Surname_property;
                    people[i]->FullName->Surname_property = people[j]->FullName->Surname_property;
                    people[j]->FullName->Surname_property = temp_surname;
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 5:

        for (short i = 0; i < size_Of_arr_peopls; i++) {
            for (short j = i + 1; j < size_Of_arr_peopls; j++) {
                if (people[i]->Year.compare(people[j]->Year) > 0) {
                    std::string temp_name = people[i]->FullName_property->Name_property;
                    people[i]->FullName_property->Name_property = people[j]->FullName->Name_property;
                    people[j]->FullName->Name_property = temp_name;

                    std::string temp_surname = people[i]->FullName->Surname_property;
                    people[i]->FullName->Surname_property = people[j]->FullName->Surname_property;
                    people[j]->FullName->Surname_property = temp_surname;
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;

    }
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
                    in >> name >> surname >> year >> pesel >> sex >> k;
                    people_n[j] = new Children(name, surname, year, pesel, sex, k);
                }
                else{
                    string Work_property, Work_experience_property ;
                    in >> name >> surname >> year >> pesel >> sex >> Work_property >> Work_experience_property;
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
    

    for (short i = 0; i < size; i++) {
        out << Name << " " << Numer << " ";
        for (short j = 0; j < size_Of_arr_peopls; j++) {

            people[j]->save(out);
           
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

                cout << "   " << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " ";
                program[i].getPerson(j)->print();
                cout << endl;
            }
            cout << endl << endl;
        }
 
    cout << endl << endl;
}