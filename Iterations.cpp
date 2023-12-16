#include <iostream>
#include <cmath>
using namespace std;

double Fp(double x);
double G(double x);

int main() {
	setlocale(LC_ALL, "Russian");
	double x, x0, E = pow(10, -6);
	int a = 1, b = 2, iter = 0;

	cout << "Уравнение:   x - 2 + sin(1 / x) = 0" << endl;

	if (abs(Fp(b)) < 1) {
		
		x = (a + b) / 2;
		do {
			++iter;
			x0 = x;
			x = G(x0);
			cout << "Итерация " << iter << ": " << x << endl;
		} while (abs(x - x0) > E);
		cout << "------------" << endl;
		cout << "x = " << x << endl << "Количество итераций: " << iter;
	}
	else cout << "Составленная функция не подходит для решения";
	return 0;
}

double Fp(double x) {
	return (cos(1 / x)) / pow(x, 2);
}

double G(double x) {
	return 2 - (sin(1 / x));
}