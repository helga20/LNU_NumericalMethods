#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// ������, ��� ������ ������� log10(x) + x - 0.5
double f(double x)
{
	return log10(x) + x - 0.5;
}

// (0.5 - log10(x))' = 1 / x * ln(10)
// (0.5 - log10(x))'' = (1 / x * ln(10))' = -1 / x^2 * ln(10)

// ����� ������� �� 0.5 - log10(x)
double p2(double x)
{
	return -1 / x * x * (log10(10) / log10(exp(x))); // -1 / x^2 * ln(10)
}

int main()
{
	// ���������� ���.���� 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a = 0.5, b = 1, e = 0.0001; // ������ [a, b] �� ������ ������� 

	cout << "�������� (a, b): " << "(" << a << "," << b << ")" << endl;
	cout << "������ ������� e = " << e << "\n\n";

	int i = 0; // ������� ��������
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
			cout << "�������� " << i << ": " << "\t" << "x_0 = " << x_0 << endl;
		}
		cout << "\nʳ������ �������� i = " << i << "\n"; // �������� ������� �������� � 
		cout << "\n����� x = " << x_0 << " �� �������� " << i << endl;
		return x_0;

	}
	else
	{
		cout << "\n������ �� ����" << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}