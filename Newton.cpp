#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
double fp1(double x);
double fp2(double x);

int main() {
	setlocale(LC_ALL, "Russian");
	double E = pow(10, -6), x, x0, d;
	int iter = 0, a = 1, b = 2;

	cout << "Уравнение:   x - 2 + sin(1 / x) = 0" << endl;

	if (f(a) * fp2(a) > 0) x0 = a;
	else if (f(b) * fp2(b) > 0) x0 = b;
	else x0 = -10000000000;
	if (x0 > -10000000000) {
		do {
			x = x0 - (f(x0) / fp1(x0));
			d = abs(x - x0);
			if (d > E) x0 = x;
			++iter;
			cout << "Итерация " << iter << ": " << x << endl;
		} while (d > E);
		cout << "------------" << endl;
		cout << "x = " << x << endl << "Количество итераций: " << iter;
	}
	else cout << "Нет решений";
	return 0;
}

double f(double x) {
	return x - 2 + sin(1 / x);
}

double fp1(double x) {
	return 1 - (cos(1 / x)) / pow(x, 2);
}

double fp2(double x) {
	return (2 * x * cos(1 / x) - sin(1 / x)) / pow(x, 4);
}