
#include "pch.h"
#include <iostream>

using namespace std;

struct Stack
{
	int info;
	Stack *next;
}*begin1, *b2, *b3;

Stack *ADD(Stack*p, int in)
{
	Stack *t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void View(Stack *p)
{
	Stack *t = p;
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}



Stack *Dell_key(Stack **p, int n)
{
	Stack *t ;
	int k = 1;
	while (*p != NULL)
	{	
		if (k <= n)
		{
			b2 = ADD(b2, (*p)->info);
			t = *p;
			*p = (*p)->next;
			delete t;
			k++;
		}
		else
		{
			b3 = ADD(b3, (*p)->info);
			t = *p;
			*p = (*p)->next;
			delete t;
			k++;
		}
		
	}
	
	while (b2 != NULL)
	{
		*p = ADD(*p, (b2)->info);
		t = b2;
		b2 = (b2)->next;
		delete t;
	}
	while (b3 != NULL)
	{
		*p = ADD(*p, (b3)->info);
		t = b3;
		b3 = (b3)->next;
		delete t;
	}

	return *p;
}

int main()
{

	cout << "Input kol   ";
	int kol, in; cin >> kol;
	for (int i = 1; i <= kol; i++)
	{
		cin >> in;
		begin1 = ADD(begin1, in);
	}
	cout << endl;
	View(begin1);
	if (kol % 2 == 0)
	{
		Dell_key(&begin1, kol/2);
		cout << endl;
		View(begin1);
	}
	else cout << "nechetnoe kolichestvo";
	
}