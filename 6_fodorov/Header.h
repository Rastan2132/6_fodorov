#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>
#include <vector>
#include <sstream>

using namespace std;

#define MAXLINE 20
#define _num 3
#define _sex 2
#define _year 4
#define _piesel 12

#define MENU "| q-Zamkac |  a-ADD uzytkownika  |  d-Usuwanie uzytkownika |  e-Redaktor |  s-Sortowac |  y-Szukaj |" 
#define stru "#       Name                 Surname	          Year		       Piesel 	       Sex"

#define MANIP setw(MAXLINE) <<  left 

int rand_data(string sex);
string rand_data(int max);

struct COLOR
{
    short text;
    short back;
};
enum ConsoleColor
{
    Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

enum Keys { Enter = 13, Backspace = 8 };
enum SpecialKeys { Left = 75, Right = 77, End = 79, Home = 71, Esc = 27, Del = 83 };

class Uzond {
    class Full_name
    {
        string Name = " ";
        string Surname = " ";
    public:
        Full_name(string Name_ = "lol", string Surname_ = "lol") :Name(Name_), Surname(Surname_) {}

        string get_name() const { return Name; }
        string get_surname() const { return Surname; }
        void set_name(string Name_) { Name = Name_; }
        void set_surname(string Surname_) { Surname = Surname_; }
        __declspec(property(get = get_name, put = set_name)) string Name_property;
        __declspec(property(get = get_surname, put = set_surname)) string Surname_property;

        friend class Uzond;
    };

    class Users
    {
    protected:
        string Year;
        string piesel;
        string sex;
        Full_name* FullName{ nullptr };
    public:
        Users(string Name_ = "lol", string Surname_ = "lol", string Year_ = "lol", string piesel_ = "lol", string sex_ = "lol") : Year(Year_), piesel(piesel_), sex(sex_), FullName{ new Full_name {Name_ , Surname_} } {}

        Users(const Users& other) : Year(other.Year), piesel(other.piesel), sex(other.sex), FullName{ new Full_name {*other.FullName} } {}

        ~Users() {
            delete FullName;
        }
        Users& operator=(const Users& other) {
            if (this != &other) {
                Year = other.Year;
                piesel = other.piesel;
                sex = other.sex;
                delete FullName;
                FullName = new Full_name(*other.FullName);
            }
            return *this;
        }
        string get_year() const { return Year; }
        void set_year(string Year_) { Year = Year_; }

        string get_piesel() const { return piesel; }
        void set_piesel(string piesel_) { piesel = piesel_; }

        string get_sex() const { return sex; }
        void set_sex(string sex_) { sex = sex_; }

        Full_name* get_fullname() const { return FullName; }
        void set_fullname(Full_name* FullName_) { FullName = FullName_; }

        __declspec(property(get = get_year, put = set_year)) string Year_property;
        __declspec(property(get = get_piesel, put = set_piesel)) string piesel_property;
        __declspec(property(get = get_sex, put = set_sex)) string sex_property;
        __declspec(property(get = get_fullname, put = set_fullname)) Full_name* FullName_property;
        void print() const {
            cout << "Name: " << FullName->get_name() << endl;
            cout << "Surname: " << FullName->get_surname() << endl;
            cout << "Year: " << Year << endl;
            cout << "Piesel: " << piesel << endl;
            cout << "Sex: " << sex << endl;
        }

        friend class Uzond;
    };

    class People : public Users
    {
    protected:
        string work;
        string work_experience;
    public:
        People(string Name_ = "lol", string Surname_ = "lol", string Year_ = "lol", string piesel_ = "lol", string sex_ = "lol", string work_ = "lol", string work_experience_ = "lol") : Users(Name_, Surname_, Year_, piesel_, sex_), work(work_), work_experience(work_experience_) {}

        string get_work() const { return work; }
        void set_work(string work_) { work = work_; }

        string get_work_experience() const { return work_experience; }
        void set_work_experience(string work_experience_) { work_experience = work_experience_; }

        __declspec(property(get = get_work, put = set_work)) string Work_property;
        __declspec(property(get = get_work_experience, put = set_work_experience)) string Work_experience_property;

        friend class Uzond;
    };

    class Children : public Users
    {
    protected:
        string kindergarten;
    public:
        Children(string Name_ = "lol", string Surname_ = "lol", string Year_ = "lol", string piesel_ = "lol", string sex_ = "lol", string kindergarten_ = "lol") : Users(Name_, Surname_, Year_, piesel_, sex_), kindergarten(kindergarten_) {}

        string get_kindergarten() const { return kindergarten; }
        void set_kindergarten(string kindergarten_) { kindergarten = kindergarten_; }

        __declspec(property(get = get_kindergarten, put = set_kindergarten)) string Kindergarten_property;

        friend class Uzond;
    };

    Users** people;
    string Name;
    string Numer;
    short  size_Of_arr_peopls;
    short size;

public:
    Uzond();
    Uzond(const Uzond& other);
    ~Uzond();

    void setPeople(Users** people_);
    Users** getPeople() const { return people; }

    int get_size_Of_arr_peopls() { return size_Of_arr_peopls; }
    void set_size_Of_arr_peopls(int size_Of_arr_peopls_) { size_Of_arr_peopls = size_Of_arr_peopls_; }

    short get_size() { return size; }
    void set_size(short size_) { size = size_; }

    void setName(string Name_) { Name = Name_; }
    string getName() const { return Name; }

    void setNumer(string Numer_) { Numer = Numer_; }
    string getNumer() const { return Numer; }

    void createPeopleArray(int size_of_people, vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork);
    Users* getPerson(int index) const;
    void removeUzond(Uzond*& program, short index);
    void removePerson(int index);

    void addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames);

    void show(Uzond program);
    void show_ones(Uzond program, int j);

    void edit(int index_1, string name, string surname, string year, string piesel, string sex);

    bool initForFile(Uzond*& program);
    void sort(Uzond*& program);
    void find(Uzond*& program);
    bool save(std::ostream& out) const;
    Users& operator[](int index) {
        return *people[index];
    }
    Uzond& operator=(const Uzond& other) {
        if (this != &other) {
            delete[] people;

            Name = other.Name;
            Numer = other.Numer;
            size_Of_arr_peopls = other.size_Of_arr_peopls;
            people = new Users * [size_Of_arr_peopls];
            for (int i = 0; i < size_Of_arr_peopls; i++) {
                people[i] = new Users(*other.people[i]);
            }
        }
        return *this;
    }


    _declspec(property(get = get_size_Of_arr_peopls, put = set_size_Of_arr_peopls)) int size_Of_arr_peopls_property;
    __declspec(property(get = get_size, put = set_size)) short size_property;
    __declspec(property(get = getName, put = setName)) string Name_property;
    __declspec(property(get = getNumer, put = setNumer)) string Numer_property;
};

void error();

Uzond* create(short size, short size_of_peopl, vector<string> arrOfNameUrzant, vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork);
void show(Uzond* program);
void add(Uzond*& program, vector<string> arr_name, vector<string> arr_suname, vector<string>arr_of_name_urzant);
char* strstr_lower(char* str_a, char* str_b);
bool isalpha_r(unsigned char a);
bool isdigit_r(unsigned char a);
vector<char> stringToArrChar(const string& str);
void edit(Uzond*& program, short index_1, short index_2);
void dell(Uzond*& program);
bool chek_file(string file);

COORD getCursorPosition(void);
void Clear(int x, int y, long cnt = 100);
bool stredit(char* str, int buffer_size, int x, int y, int cursor = 0, bool clear_after = true);
void showcursor(bool flag);
void setCursorPosition(int x, int y);
COORD getConsoleSize();
COLOR GetColor();
WORD GetColorWord();
void SetColor(COLOR Color);
void print_find(char* str, short str_size, char* keyword, short key_size, int text = -1, int back = -1);

void DeleteCh(char* str, int& cursor, int& term);
void InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb);


std::istream& operator>>(Uzond*& program, std::istream& in);
std::ostream& operator<<(std::ostream& out, const Uzond& program);