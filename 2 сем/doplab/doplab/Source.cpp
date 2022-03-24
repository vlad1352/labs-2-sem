#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int a[5], max = 0, min, sum = 0;
	ifstream fin;
	ofstream fout("B.txt");
	fin.open("A.txt");
	for (int i = 0; i < 5; i++)
	{
		fin >> a[i];
		fout << a[i] << " ";
	}
	fout << endl;
	for (int i = 0; i < 5; i++)
		if (max < a[i]) max = a[i];
	min = max;
	for (int i = 0; i < 5; i++)
		if (min > a[i]) min = a[i];
	for (int i = 0; i < 5; i++)
	{
		cout << a[i];
		sum += a[i];
	}
	sum = sum - min - max;
	cout << endl << sum << endl;
	fout << sum;
	fin.close();
	fout.close();
	system("pause");
	return 0;
}