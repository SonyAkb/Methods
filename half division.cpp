#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return x - 2 + sin(1 / x);
}

int main() {
	setlocale(LC_ALL, "Russian");
	double E = pow(10, -6), a = 1, b = 2, c, iter = 0;
	cout << "Уравнение:   x - 2 + sin(1 / x) = 0" << endl;
	do {
		c = (a + b) / 2;
		if (f(a) * f(c) > 0) a = c;
		else b = c;
		++iter;
		cout << "c = " << c << endl;
	} while (abs(a - b) > E);

	cout << "x = " << c << endl << "Количество итераций: " << iter;
	return 0;
}