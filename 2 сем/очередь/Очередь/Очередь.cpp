#include "pch.h"
#include <iostream>

using namespace std;

struct spis
{
	int info;
	spis *next;
	spis *prev;
}*begin1, *end1;

void Newspis(int inf)
{
	spis *t = new spis;
	t->info = inf;
	t->next = t->next = NULL;
	begin1 = end1 = t;
}

void view_begin(spis *p)
{
	spis *t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = 
			t->next;
	}
}

void view_end(spis *p)
{
	spis *t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->prev;
	}
}

void zadanie()
{
	spis *tmp = begin1, *tmp2 = NULL;
	while (tmp != NULL)
	{
		if ((tmp->info) % 10 == 5)
		{
			if (tmp->prev == NULL)
			{
				tmp2 = tmp;
				begin1 = begin1->next;
				begin1->prev = NULL;
			}
			else
			{
				if (tmp->next == NULL)
				{
					tmp2 = tmp;
					end1 = end1->prev;
					end1->next = NULL;
				}
				else
				{
					tmp2 = tmp;
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
				}
			}
			tmp = tmp->next;
			delete tmp2;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	
}

void add_begin( int inf)
{
	spis *t = new spis;
	t->prev = NULL;
	t->info = inf;
	t->next = begin1;
	begin1->prev = t;
	begin1 = t;
}

void add_end(int inf)
{
	spis *t = new spis;
	t->next = NULL;
	t->info = inf;
	t->prev = end1;
	end1->next = t;
	end1 = t;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << " Что хотите сделать\n 1 - Создать очередь\n 2 - Добавить\n 3 - Просмотреть\n 4 - задание \n 5 - Выйти из программы \n";
		int k; cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "Введите первый элемент :";
			int inf; cin >> inf;
			Newspis(inf);
		}break;
		case 2:
		{
			cout << "Добавить в начало - 1, в - конец - 2\n";
			int q; cin >> q;
			switch (q)
			{
			case 1:
			{
				cout << "Введите количество элементов : ";
				int e, inf; cin >> e;
				for (int i = 0; i < e; i++)
				{
					cout << "\nВведите элемент: ";
					cin >> inf;
					add_begin(inf);
				}
			}break;
			case 2:
			{
				cout << "Введите количество элементов : ";
				int e, inf; cin >> e;
				for (int i = 0; i < e; i++)
				{
					cout << "\nВведите элемент: ";
					cin >> inf;
					add_end(inf);
				}
			}break;
			}
		}break;
		case 3:
		{
			cout << "Просмотр с начала - 1, с конца - 2  ";
			int w; cin >> w;
			switch (w)
			{
			case 1:
			{
				view_begin(begin1);
			}break;
			case 2:
			{
				view_end(end1);
			}
			}
		}break;
		case 4:
		{
			zadanie();
		}break;
		case 5:
		{
			return 0;
		}break;
		default: cout << "Введите правильно\n";
		}
	}
}