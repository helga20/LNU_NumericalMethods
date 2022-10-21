#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// фунція, яка містить рівняння log10(x) + x - 0.5
double f(double x)
{
	return log10(x) + x - 0.5;
}

// (0.5 - log10(x))' = 1 / x * ln(10)
// (0.5 - log10(x))'' = (1 / x * ln(10))' = -1 / x^2 * ln(10)

// друга похідна від 0.5 - log10(x)
double p2(double x)
{
	return -1 / x * x * (log10(10) / log10(exp(x))); // -1 / x^2 * ln(10)
}

int main()
{
	// підключення укр.мови 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a = 0.5, b = 1, e = 0.0001; // відрізок [a, b] та задана точність 

	cout << "Інтервал (a, b): " << "(" << a << "," << b << ")" << endl;
	cout << "Задана точність e = " << e << "\n\n";

	int i = 0; // кількість ітерацій
	double x_0;
	if (f(a) * f(b) < 0)
	{
		while (fabs(b - a) >= e)
		{
			x_0 = (b * f(a) - f(b) * a) / (f(a) - f(b));
			if (f(x_0) * f(b) < 0)
			{
				a = x_0;
			}
			else if (f(a) * f(x_0) < 0)
			{
				b = x_0;
			}
			else
				return x_0;
			i++;
			cout << "Ітерація " << i << ": " << "\t" << "x_0 = " << x_0 << endl;
		}
		cout << "\nКількість ітерацій i = " << i << "\n"; // виводимо кількість ітерацій і 
		cout << "\nКорінь x = " << x_0 << " на ітерації " << i << endl;
		return x_0;

	}
	else
	{
		cout << "\nКоренів не існує" << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}