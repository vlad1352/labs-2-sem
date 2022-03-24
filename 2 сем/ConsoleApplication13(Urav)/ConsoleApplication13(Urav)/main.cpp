#include<iostream>
#include <cmath>
using namespace std;
double search(double x1, double x2);
double count(double x);
void main(){
	double b = 8, a = 1, h = 0.5;
	cout << "korni na 1 do 8\nln(x)-5cos(x)" << endl;
	for (double i = a; i <= b; i += h){
		if (count(i)*count(i + h) < 0) {
			cout << search(i, i + h) << " " << count(search(i, i + h)) << endl;
		}
	}
}

double search(double x1, double x2) {
	double E = 0.000000001;
	double result;



	do {
		
		result = x2 - ((x2 - x1) / (count(x2) - count(x1))) * count(x2);
		x1 = x2;
		x2 = result;
	} while (abs(result - x1) >= E);

	return result;
}
double count(double x){
	return (log(x) - (5*cos(x)));
}