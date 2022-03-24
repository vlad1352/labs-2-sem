#include <iostream>
using namespace std;

double f(double x) {
	return pow(x, 2) - 10 * pow(sin(x), 2) + 2;
}

double search(double x1, double x2) {
	double E = 0.0000001;
	double y, res = 0;

	
	
	do {
		y = res;
		res = x2 - ((x2 - x1) / (f(x2) - f(x1))) * f(x2);
		x1 = x2;
		x2 = y;
	} while (fabs(res - x2) >= E);

		return res;
}


void main(){

	int a = -1, b = 3;
    double h = 0.01;
	for (double i = a; i <=b; i+= h)
		if (f(i)*f(i + h) < 0) {
			cout << search(i, i + h) << " " << f(search(i, i + h)) << endl;
		}
}