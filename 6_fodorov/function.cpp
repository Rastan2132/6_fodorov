#include "Header.h"

bool chek_file(string file) {
	ifstream in;
	in.open(file, ios::in);

	auto rez = 1;
	if (in.is_open())
	{
		if (in.peek() == char_traits<char>::eof())
			rez = 0;
		in.close();
	};
	return rez;
}

void error()
{
	Beep(800, 150);
	cout << "ERROR!" << endl << endl;
	system("pause");
}

bool isdigit_r(unsigned char a) { return (a >= '0' && a <= '9'); }

bool isalpha_r(unsigned char a)
{
	bool rez = ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '-');

	return rez;
}

Uzond* create(short size, short size_of_peopl, vector<string> arrOfNameUrzant, vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork) {
	Uzond* arr = new Uzond[size];
	
	for (int i = 0; i < size; i++) {
		arr[i].Name_property = arrOfNameUrzant[rand() % arrOfNameUrzant.size()];
		arr[i].Numer_property = rand_data(_num);
		arr[i].size_property = size;
		arr[i].size_Of_arr_peopls_property = size_of_peopl;
		arr[i].createPeopleArray( arrOfNames, arrOfSurnames, arrOfNameKindergarten, arrOfWork);

	}
	return arr;
}

int rand_data(string sex)								/// �� 0 �� 9 ���. �� 10 �� 19 ���
{
	if (sex == "man")
		return rand() % 5;
	else
		return rand() % 5 + 5;

}

string rand_data(int max)
{
	string rez;
	if (max == 2)
	{
		if ((rand() % 2) == 1)
		{
			rez = "man";
		}
		else
		{
			rez = "women";
		}
		return rez;
	}
	else if (max == 4)
	{
		int year = rand() % (2023 - 1900 + 1) + 1900;
		return to_string(year);
	}
	else if (max == 12)
	{
		unsigned int number = 0;
		for (int i = 0; i < 12; i++) {
			number = number * 10 + rand() % 10;
		}

		return to_string(number);
	}
	else if (max == 3)
	{
		long long number = 0;
		for (int i = 0; i < 3; i++) {
			number = number * 10 + rand() % 10;
		}
		return to_string(number);
	}
	return "error";
}

void add(Uzond*& program, vector<string> arr_name, vector<string> arr_surname, vector<string> arr_of_name_urzant, vector<string> arrOfNameKindergarten, vector<string> arrOfWork)
{
	cout << "�hcesz dodac urzond lub osobe(u lub o)" << endl;
	
	switch (_getch())
	{
	case (117): {
		Uzond* program_n = nullptr;
		short size = program->size_property;
		size++;
		program->size_property = size;
		program_n = new Uzond[size];
		program_n->size_property = size;
		for (int i = 0; i < size - 1; i++) {
			program_n[i] = program[i];
		}
		program_n[size - 1].Name_property = arr_of_name_urzant[rand() % arr_of_name_urzant.size()];
		program_n[size - 1].Numer_property = rand_data(_num);
		program_n[size - 1].size_property = size;
		program_n[size - 1].size_Of_arr_peopls_property = program_n->size_Of_arr_peopls_property;
		program_n[size - 1].createPeopleArray( arr_name, arr_surname, arrOfNameKindergarten, arrOfWork);
		delete[] program;

		program = program_n;

		break;
	}
	case (111): {
		cout << "Ty chces dodac People lub Children? (1 or 2)" << endl;
		bool flag;
		switch (_getch())
		{
		case ('1'):
			flag = 0;
			break;
		case ('2'):
			flag = 1;
			break;
		default:
			flag = 0;
			break;
		}
		short size_of_peopl = program->size_Of_arr_peopls_property;
		size_of_peopl++;
		for (short i = 0; i < program->size_property; i++)
			program[i].size_Of_arr_peopls_property = size_of_peopl;
		for (int i = 0; i < program->size_property; i++)
			program[i].addPerson(arr_name, arr_surname, arrOfNameKindergarten, arrOfWork, flag);
		break;
	}
	default:
		break;
	}
}

void dell(Uzond*& program)
{
	cout << "Usunac uzytkownika lub uzytkownika? (u lub o)" << endl;
	switch (_getch()) {
	case (117):
	{
		if (program->size_property <= 0) {
			error();
		}
		cout << "Wybierz numer Uzond, ktory chcesz usunac (1 - " << program->size_property << "):" << endl;
		int num = 0;
		cin >> num;
		if (num < 1 || num > program->size_property) {
			error();
		}
		removeUzond(program, num);
		short size = program->size_property;
		size--;
		program->size_property = size;
		break;
	}

	case (111):
	{

		cout << "Wybierz numer uzytkownika, ktorego chcesz usunac(1 - " << program->size_Of_arr_peopls_property << "):" << endl;
		int num = 0;
		cin >> num;
		if (num < 1 || num >  program->size_Of_arr_peopls_property) {
			error();
		}

		for (int i = 0; i < program->size_property; i++) {
			program[i].removePerson(num);
		}
		short size = program->size_Of_arr_peopls_property;
		size--;
		for (short i = 0; i < size; i++)
			program[i].size_Of_arr_peopls_property = size;
		break;
	}
	}
}

void edit(Uzond*& program, short index_1, short index_2)
{
	system("cls");
	ShowCursor(1);
	if (index_1 < 0 || index_2 < 0)
	{
		error();
	}
	
	cout << "Wstepne dane:" << endl;
	program[index_1].getPerson(index_2)->print();
	cout << "Podaj Name Surname Year Pesel i sex: ";
	program[index_1].getPerson(index_2)->edit();
	ShowCursor(0);
}

void print_find(char* str, short str_size, char* keyword, short key_size, int text, int back)
{
	if (str == nullptr || keyword == nullptr) return;

	size_t str_len = strlen(str);
	size_t key_len = strlen(keyword);

	if (str_len > str_size || str_len < 0 || key_len > key_size || key_len < 0) return;

	COORD start, cursor;

	start = getCursorPosition();
	cout << left << setw(str_size) << str;
	cursor = getCursorPosition();
	showcursor(false);

	COLOR DefColor = GetColor();
	COLOR FindColor;

	FindColor.text = (text == -1) ? DefColor.text : text;
	FindColor.back = (back == -1) ? DefColor.back : back;

	char* ptr = strstr_lower(str, keyword);
	short index = 0;

	while (ptr != nullptr)
	{
		index = (int)(ptr - str);                    //������� ������� ����� � ������ � 
		setCursorPosition(start.X + index, start.Y); //��������� � ������� �����.

		// ������� ����� � �������� �����.
		SetColor(FindColor);
		for (int j = 0; j < key_len; j++) cout << str[index + j];
		SetColor(DefColor);

		//���� �����.
		ptr = strstr_lower(ptr + key_len, keyword);
	}

	setCursorPosition(cursor.X, cursor.Y);
	showcursor(true);
}

Uzond& Uzond::operator=(const Uzond& other) {
	if (this != &other) {
		// �������� ������� ����
		Name = other.Name;
		Numer = other.Numer;
		size_Of_arr_peopls = other.size_Of_arr_peopls;
		size = other.size;


		delete[] people;
		people = new Users * [size_Of_arr_peopls];
		for (int i = 0; i < size_Of_arr_peopls; i++) {
			if (dynamic_cast<People*>(other.people[i])) {
				people[i] = new People(*dynamic_cast<People*>(other.people[i]));
			}
			else if (dynamic_cast<Children*>(other.people[i])) {
				people[i] = new Children(*dynamic_cast<Children*>(other.people[i]));
			}
			else {
				people[i] = new Users(*other.people[i]);
			}
		}
	}
	return *this;
}
char* strstr_lower(char* str_a, char* str_b)
{


	if (str_a == nullptr || str_b == nullptr)
		return nullptr;


	for (int i = 0;; i++)
	{
		if (str_a[i] == '\0') return nullptr;

		for (int j = 0, k = i;; j++, k++)
		{
			if (str_b[j] == '\0') return (str_a + i);
			if (tolower(str_a[k]) != tolower(str_b[j])) break;
		}
	}
}

vector<char> stringToArrChar(const string& str) {
	vector<char> char_array(str.begin(), str.end());
	char_array.push_back('\0');
	return char_array;
}

void find(Uzond*& program)
{
	if (program == nullptr || program->get_size() == 0 || program->get_size_Of_arr_peopls() == 0)
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
	cout << endl;
	cout << stru << endl;
	hat = getCursorPosition();

	COORD temp_pos;
	short len = 0;

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

	system("cls");
	cout << " Esc - Wejscie" << endl << endl;
	cout << "Szukaj: ";
	enter = getCursorPosition();

	cout << endl << stru << endl;
	hat = getCursorPosition();
	//������� ����� ���������� ������


	for (short l = 0; l < program->size_property; l++)
	{
		cout << "Rezultat o " << l + 1 << " linii" << endl;
		for (short i = 0; i < program->size_Of_arr_peopls_property; i++)
		{
			program[l].getPerson(i)->find(keyword);
		}
		cout << endl;
	}
	system("pause");
	delete[] keyword; keyword = nullptr;
}