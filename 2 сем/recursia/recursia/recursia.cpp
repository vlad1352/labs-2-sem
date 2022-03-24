#include "pch.h"
#include <iostream>

using namespace std;

int recursia(int x)
{
	if (x == 1) 
	{
		return 1;
	}
		else if (x == 0)
		{	
		return 0;
		}
		else  if (x > 1)
		{
		return (recursia(x - 1) + recursia(x - 2));
		}
}
int nerecursia(int y)
{
	int f1 = 0, f2 = 1, fn;
	if (y == 1)
	{
		return 1;
	}
	else if (y == 0)
	{
		return 0;
	}
	else  if (y > 1)
	{
		for (int i = 1; i < y; i++)
		{
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
	}
	return fn;
}


int main()
{
	while (true)
	{
		cout << "Vvedite chislo\n";
		int n;
		cin >> n;
		cout << "1 - recursia, 2 - ne recursia, 3 - exit\n";
		int k;
		cin >> k;
		switch (k)
		{
			case 1:
			{
			cout << recursia(n) << endl;
			} break;
			case 2:
			{
				cout << nerecursia(n) << endl;
			} break;
			case 3:
			{
				return 0;
			} break;
		}
	 }
}

