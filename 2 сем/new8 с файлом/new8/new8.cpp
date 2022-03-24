#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

struct tabl
{
	char fio[40];
	int group, god, math, phis, inform, chem;
	double s_b;
};

int main()
{
	int n = 0;
	tabl stud[100];
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "				Что вы хотите сделать" << endl << "1 - создать список " << endl << "2 - редактировать список " << endl
			<< "3 - просмотреть список " << endl << "4 - выход из программы" << endl << "5 - Индивидуальное задание " << endl;
		int k;
		cin >> k;
		switch (k)
		{
			case 1 :
			{
				cout << "Введите число студентов  ";
				int q; cin >> q;
				ofstream file("spisok.txt");
				for (int i = 0; i < q; i++)
				{
					cout << "Введите фамилию, номер группы, год рождения и оценки по физике, математике, информатике, химии : " << endl;
					cin >> stud[i].fio >> stud[i].group >> stud[i].god >> stud[i].phis >> stud[i].math >> stud[i].inform >> stud[i].chem;
					stud[i].s_b = (stud[i].phis + stud[i].math + stud[i].inform + stud[i].chem)/4;
					n++;
					file << stud[i].fio << " " << stud[i].group << " " << stud[i].god << " " << stud[i].phis << 
						" " << stud[i].math << " " << stud[i].inform << " " << stud[i].chem << " " << stud[i].s_b << endl;
				}
				file.close();
			} break;
			case 2:
			{
				cout << endl << "1 - добавить студентов в спсок, 2 - редактировать список" << endl;
				int w; cin >> w;
				switch (w)
				{
					case 1:
					{
						cout << "Введите число студентов  ";
						int q; cin >> q;
						ofstream file;
						file.open("spisok.txt", ios::app);
						for (int i = 0; i < q; i++)
						{
							cout << "Введите фамилию, номер группы, год рождения и оценки по физике, математике, информатике, химии : " << endl;
							cin >> stud[i].fio >> stud[i].group >> stud[i].god >> stud[i].phis >> stud[i].math >> stud[i].inform >> stud[i].chem;
							stud[i].s_b = (stud[i].phis + stud[i].math + stud[i].inform + stud[i].chem) / 4;
							n++;
							file << stud[i].fio << " " << stud[i].group << " " << stud[i].god << " " << stud[i].phis << " " <<
								" " << stud[i].math << " " << stud[i].inform << " " << stud[i].chem << "  " << " " << stud[i].s_b << endl;
						}
						file.close();
					} break;

					case 2:
					{
						int k = 0;
						string line;
						ifstream fil;
						fil.open("spisok.txt");
						if (!fil.is_open())
						{
							cout << "error open" << endl;
						}
						while (!fil.eof())
						{
							getline(fil, line);

							k++;
						}

						fil.close();
						ifstream ful;
						ful.open("spisok.txt");
						for (int i = 0; i < k - 1; i++)
						{

							ful >> stud[i].fio >> stud[i].god >> stud[i].group >> stud[i].phis >> stud[i].math >>
								stud[i].inform >> stud[i].chem >> stud[i].s_b;
							cout << stud[i].fio << " " << stud[i].god << " " << stud[i].group << " " << stud[i].math << " " << stud[i].phis <<
								" " << stud[i].inform << " " << stud[i].chem << " " << stud[i].s_b << endl;

						}
						ful.close();
						cout << "введите № студента начиная с 0" << endl;
						int e; cin >> e;

						cout << "Введите фамилию, номер группы, год рождения и оценки по физике, математике, информатике, химии : " << endl;
						cin >> stud[e].fio >> stud[e].group >> stud[e].god >> stud[e].phis >> stud[e].math >> stud[e].inform >> stud[e].chem;
						stud[e].s_b = (stud[e].phis + stud[e].math + stud[e].inform + stud[e].chem) / 4;
						ofstream file;
						file.open("spisok.txt");
						if (!file.is_open())
						{
							cout << "ошибка" << endl;
						}
						for (int i = 0; i < k - 1; i++)
						{
							file << stud[i].fio << " " << stud[i].group << " " << stud[i].god << " " << stud[i].phis << " " <<
								" " << stud[i].math << " " << stud[i].inform << " " << stud[i].chem << "  " << " " << stud[i].s_b << endl;
						}
						file.close();
					} break;

				}
			} break;
			case 3:
			{
				string z;
				ifstream file("spisok.txt");
				if (file.is_open())
				{
					while (!file.eof())
					{
						getline(file, z);
						cout << z << endl;
					}
				}file.close();
			}break;
			case 4:
			{
				return 0;
			}break;
			case 5 :
			{
				int k = 0;
				string line;
				ifstream fil;
				fil.open("spisok.txt");
				if (!fil.is_open())
				{
					cout << "error open" << endl;
				}
				while (!fil.eof())
				{
					getline(fil, line);

					k++;
				}

				fil.close();
				ifstream ful;
				ful.open("spisok.txt");
				for (int i = 0; i < k - 1; i++)
				{

					ful >> stud[i].fio >> stud[i].god >> stud[i].group >> stud[i].phis >> stud[i].math >>
						stud[i].inform >> stud[i].chem >> stud[i].s_b;
					cout << stud[i].fio << " " << stud[i].god << " " << stud[i].group << " " << stud[i].math << " " << stud[i].phis <<
						" " << stud[i].inform << " " << stud[i].chem << " " << stud[i].s_b << endl;

				}
				ful.close();
				cout << "\n-----------— Решение задания------------" << endl;
				ofstream fol("zadanie.txt");
				for (int i = 0; i < k - 1; i++)
				{
					if (((stud[i].phis == 4) || (stud[i].phis == 5)) && (stud[i].chem > 8) && (stud[i].inform > 8) && (stud[i].math > 8))
					{
						fol << stud[i].fio << " " << stud[i].group << " " << stud[i].god << " " << stud[i].phis <<
							" " << stud[i].math << " " << stud[i].inform << " " << stud[i].chem << "  средний балл : " << stud[i].s_b << endl;
					}
				}

				fol.close();
				ifstream fl("zadanie.txt");
				while (!fl.eof())
				{
					getline(fl, line);

					cout << line << endl;
				}
				fl.close();
				break;


			}break;
			default: cout << "введите правильно";
		}
	}
}
