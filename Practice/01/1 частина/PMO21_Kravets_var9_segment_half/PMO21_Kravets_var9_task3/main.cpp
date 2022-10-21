#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// фунція, яка містить рівняння y=x^4-3x^3+8x^2-5
double f(double x)
{
	double f;
	f = pow(x, 4) - 3 * pow(x, 3) + 8 * pow(x, 2) - 5;
	return f;
}

int main()
{
	// підключення укр.мови 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 

	double a = -1, b = 0, e = 0.0001, x; // відрізок [a, b] та задана точність  
	int i = 0; // змінна для підрахунку кроків

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "e = " << e << endl;

	// якщо виконується умова f(a)*f(b)<0, то шукаємо середину відрізка[a,b] x =(a+b)/2
	if (f(a) * f(b) < 0)
	{
		cout << "Корені знайдено" << endl;
		while (1)
		{
			x = (a + b) / 2.0;
			i = i + 1;
			if (fabs(f(x)) < e) break; // якщо |f(x)|<e, то виходимо з циклу  
	// якщо f(a)*f(x)< 0, то шукаємо на якому кінці відрізка змінюється знак і замінюємо цей кінець на x
			if ((f(a) * f(x) < 0))  
			{
				a = a;
				b = x;
			}
			else
			{
				a = x;
				b = b;				
			}
			// виводимо значення a та b
			cout << "a = " << x << '\t';
			cout << "b = " << x << endl;
		}
		// виводимо значення x та i
		cout << "Корінь x = " << x << "\n";
		cout << "Кількість кроків i = " << i << "\n";
	}
	// якщо НЕ виконується умова f(a)*f(b)<0, то виводимо повідомлення
	else
	{
		cout << "Коренів не існує" << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
