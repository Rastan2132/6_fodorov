#include "Header.h"

int main()
{
	bool work = 1;
	short urz_num, p_num;
	cout << "Enter Your name and surname: ";
	showcursor(1);
	string line, name, surname;
	getline(cin, line);
	name = line.substr(0, line.find_first_of(";"));
	line = line.substr(line.find_first_of(";") + 1);
	surname = line.substr(0, line.find_first_of(";"));

	system("cls");
	static Full_name autor(name, surname);
	setCursorPosition(30, 10);
	COLOR Witamy;
	Witamy.back = 0;
	Witamy.text = 2;
	SetColor(Witamy);
	cout << "Witamy, " << autor.Name_property << " " << autor.Surname_property<<" !!!";
	setCursorPosition(0, 20);
	Witamy.back = 0;
	Witamy.text = 15;
	SetColor(Witamy);
	system("pause");
	setCursorPosition(0, 0);
	showcursor(0);

	Uzond* program{ nullptr };

	vector<string> NAMES = { "Alexander","Maxim","Dmitry","Sergei","Ivan","Anna","Maria","Olga","Elena","Natalia" };
	vector<string> SURNAMES = { "Ivanov","Petrov","Sidorov","Smirnov","Kuznetsov","Ivanova","Petrova","Sidorova","Smirnova","Kuznetsova" };
	vector<string>NAMES_of_Uzond = { "Urzad_Pracy","Urzad_Spraw","Urzad_Skarbowy","Urzad_s._cywilnego" };
	vector<string> arrOfNameKindergarten = { "Krasnoludek", "Sloneczko", "Bajka", "Promyczek" };
	vector<string> arrOfWork = { "nauczyciel", "lekarz", "informatyk", "sprzedawca", "prawnik" };
//	if (chek_file("Uzonds.txt") == 0)
//	{
		short size = rand() % 10 + 1;
		short size_of_peopl = rand() % 10 + 1;
		program = create(size, size_of_peopl, NAMES_of_Uzond, NAMES, SURNAMES,  arrOfNameKindergarten, arrOfWork);

		program->size_property = size;
		program->size_Of_arr_peopls_property = size_of_peopl;
//	}
//	else
//	{
//		std::ifstream file("Uzonds.txt");
//		program >> file;
//		file.close();
//	}


	if (program->size_property < 0)
	{
		error();
		program->size_property = 0;
	}

	ShowCursor(0);
	do
	{
		program->show(program);
		switch (_getch())
		{
		case (113):
			work = false;
			break;
		case (97):
			add(program, NAMES, SURNAMES, NAMES_of_Uzond, arrOfNameKindergarten, arrOfWork);
			break;
		case (100):
		//	dell(program);
			break;
		case (101):
		//	do {
		//		cout << "wprowadz numer urzendu i numer osoby" << endl;
		//		cin >> urz_num >> p_num;
		//		if (urz_num > 0 && p_num > 0 && urz_num <= program->size_property && p_num <= program->size_Of_arr_peopls_property)
		//			break;
		//		error();
		//	} while (true);
		//	edit(program, urz_num - 1, p_num - 1);
			break;
		case (115):
		//	program->sort(program);
			break;
		case (121):
		//	program->find(program);
			break;
		}
	} while (work);
	//std::ofstream  file("Uzonds.txt");
//	for (short i = 0; i < program->size_property; i++) {
	//	file << program[i];
	//}
	//file.close();

}
