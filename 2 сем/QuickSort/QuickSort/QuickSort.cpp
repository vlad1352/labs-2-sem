#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

struct spisok
{
	char  name[30];
	char data_r[10];
	int kod_g, tarif, num_v_g, num_a;
	double time_r;
};
 

int kol()
{
	string line;
	int k = 0;
	ifstream fil;
	fil.open("spisok.txt");
	while (!fil.eof())
	{
		getline(fil, line);
		k++;
	}
	fil.close();
	return k;
}

void zapis(spisok spis[], int k)
{
	ifstream fin;
	fin.open("spisok.txt");
	for (int i = 0; i < k - 1; i++)
	{
		fin >> spis[i].name >> spis[i].kod_g >> spis[i].data_r >> spis[i].time_r
			>> spis[i].tarif >> spis[i].num_a >> spis[i].num_v_g;
	}
	fin.close();
}

void line_p(spisok spis[], int k, double x)
{
	for (int i = 0; i < k; i++)
	{
		if (spis[i].time_r == x)
		{
			cout << spis[i].name << "  " << spis[i].kod_g << "  " << spis[i].data_r << "  " 
				<< spis[i].time_r << "  " << spis[i].tarif <<
				"  " << spis[i].num_a << "  " << spis[i].num_v_g << endl;
		}
	}
}

void qviksort(spisok *spis, int left, int right)
{
	int i = left, j = right;
	while (i <= j)
	{

		while (spis[i].time_r < spis[(left + right + 1) / 2].time_r) i++;
		while (spis[j].time_r > spis[(left + right + 1) / 2].time_r) j--;
		if (i <= j)
		{
			swap(spis[i++], spis[j--]);
		}
	}
	if (left < j)
		qviksort(spis, left, j);
	if (right > i)
		qviksort(spis, i, right);

}

void dv_p(spisok spis[], double x)
{
	/*int i = 0, j = k - 1, m;
	while (i < j)
	{
		m = (i + j) / 2;
		if (x > spis[i].time_r) i = m + 1;
		else j = m;
		if (spis[i].time_r == x)
		{
			cout << spis[i].name << "  " << spis[i].kod_g << "  " << spis[i].data_r << "  "
				<< spis[i].time_r << "  " << spis[i].tarif <<
				"  " << spis[i].num_a << "  " << spis[i].num_v_g << endl;
		}
	}*/

	int n = 0;
	string line;
	ifstream file;
	file.open("spisok.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			n++;
		}
		file.close();
		file.open("spisok.txt");
		spisok *spis = new spisok[n];
		for (int c = 0; c < n; c++)
		{
			file >> spis[c].name >> spis[c].kod_g >> spis[c].data_r >> spis[c].time_r >>
				spis[c].tarif >> spis[c].num_a >> spis[c].num_v_g;
		} 
		file.close();
		cout << endl;
		qviksort(spis, 0, n - 1);
		int i = 0, j = n - 1, m;
		while (i <= j)
		{
			m = (i + j) / 2;
			if (x > spis[m].time_r) i = m + 1;
			else j = m - 1;
			if (spis[m].time_r == x) 
			{
				cout << spis[m].name << "  " << spis[m].kod_g << "  " << spis[m].data_r << "  " << spis[m].time_r << "  "
					<< spis[m].tarif << "  " << spis[m].num_a << "  " << spis[m].num_v_g << endl;
				break;
			}
		}
	}
}

void s_vb(spisok spis[])
{

	int n = 0;
	string line;
	ifstream file;
	file.open("spisok.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			n++;
		}
		file.close();
		file.open("spisok.txt");
		int i, j;
		for (i = 0; i < n - 2; i++)
		{
			for (j = i + 1; j < n - 1; j++)
			{
				if (spis[i].time_r > spis[j].time_r)
					swap(spis[j], spis[i]);

			}
		}
	}
}


int main()
{
	int n = 0;
	spisok spis[255];
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "				Что вы хотите сделать\n" << "1 - создать список \n" << "2 - добавить \n" 
			<< "3 - просмотреть список\n" << "4 - Индивидуальное задание\n" << "5 - поиск \n"  
			<< "6 - сортировка\n" << "7 - выход из программы" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case 1: // создание 
		{
			ofstream fin("spisok.txt");
			cout << "Введите количество абонентов: ";
			int l; cin >> l;
			for (int i = 0; i < l; i++)
			{
				cout << "Введите название города и его код ";
				cin >> spis[i].name >> spis[i].kod_g;
				fin << spis[i].name << "  " << spis[i].kod_g << "  ";
				cout << "Введите дату разговора, время разговора, тариф, номер телефона и номер абонента в городе ";
				cin >> spis[i].data_r >> spis[i].time_r >> spis[i].tarif >> spis[i].num_a >> spis[i].num_v_g;
				fin << "  " << spis[i].data_r << "  " << spis[i].time_r << "  " << spis[i].tarif <<
					"  " << spis[i].num_a << "  " << spis[i].num_v_g << endl;
			}
			fin.close();
		}break;
		case 2: // добавление
		{
			ofstream fin("spisok.txt", ios::app);
			cout << "Введите количество абонентов: ";
			int l; cin >> l;
			for (int i = 0; i < l; i++)
			{
				cout << "Введите название города и его код ";
				cin >> spis[i].name >> spis[i].kod_g;
				fin  << spis[i].name << "  " << spis[i].kod_g << "  ";
				cout << "Введите дату разговора, время разговора, тариф, номер телефона и номер абонента в городе ";
				cin >> spis[i].data_r >> spis[i].time_r >> spis[i].tarif >> spis[i].num_a >> spis[i].num_v_g;
				fin << "  " << spis[i].data_r << "  " << spis[i].time_r << "  " << spis[i].tarif <<
					"  " << spis[i].num_a << "  " << spis[i].num_v_g << endl;
			}
			fin.close();
		}break;
		case 3: //вывод на экран
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
			double time = 0, sum = 0;
			int k = kol();
			zapis(spis, k);
			cout << "Введите название города  ";
			char name[30]; cin >> name;
			for (int i = 0; i < k - 1; i++)
			{
				if (strcmp(spis[i].name, name) == 0)
				{
					time += spis[i].time_r;
					sum += spis[i].tarif*spis[i].time_r;
				}
			}
			cout << time << endl << sum;
		}break;
		case 5:
		{
			cout << "1 - линейный поиск, 2 - деление пополам\n";
			int q; cin >> q;
			switch (q)
			{
			case 1:
			{
				int k = kol();
				cout << "Введите время разговоров \n";
				double time; cin >> time;
				line_p(spis, k - 1, time);
			} break;
			case 2:
			{
				int k = kol();
				zapis(spis, k);
				double time;
				cout << "Введите время "; cin >> time;
				dv_p(spis, time);
			} break;
			}
		} break;
		case 6:
		{
			cout << "1 - прямой выбор, 2 - QuickSort\n";
			int q; cin >> q;
			switch (q)
			{
			case 1:
			{
				k = kol();
				zapis(spis, k);
				s_vb(spis);
				for (int i = 0; i < k - 1; i++)
				{
					cout << spis[i].name << "  " << spis[i].kod_g << "  " << spis[i].data_r << "  "
						<< spis[i].time_r << "  " << spis[i].tarif <<
						"  " << spis[i].num_a << "  " << spis[i].num_v_g << endl;
				}
			} break;
			case 2:
			{
				int k = kol() - 1;
				zapis(spis, k + 1);
				qviksort(spis, 0, k);
				for (int m = 0; m < k; m++)
				{
					cout << spis[m].name << "  " << spis[m].kod_g << "  " << spis[m].data_r << "  " << spis[m].time_r << "  "
						<< spis[m].tarif << "  " << spis[m].num_a << "  " << spis[m].num_v_g << endl;
				}
			} break;
			}
		} break;
		case 7:
		{
			return 0;
		}break;
		default: cout << "введите правильно";
		}
	}
}
