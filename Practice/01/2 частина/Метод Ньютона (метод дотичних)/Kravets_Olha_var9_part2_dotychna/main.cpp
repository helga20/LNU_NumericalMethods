#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// фунція, яка містить рівняння log10(x) +x-0.5
double f(double x)
{
	return log10(x) + x - 0.5;
}

// похідна від log10(x)+x-0.5
double p(double x)
{
	return (1 / x * (log10(10) / log10(exp(x))) + 1); // (1/x*ln(10))+1
}

// друга похідна від log10(x)+x-0.5
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

	double x, x_0, x_1, x_2, k;
	int i = 0; // кількість ітерацій
	if (f(a) * f(b) < 0)
	{
			// заміна a на b
			if (f(a) * p2(a) > 0)
			{
				x_0 = a;
			}
			else
			{
				x_0 = b;
			}
			while (1)
			{

				x_1 = x_0 - (f(x_0) / p(x_0));
				x_2 = x_1 - (f(x_1) / p(x_1));

				if (abs(x_2 - x_1) < e)
				{
					break;
				}
				x_0 = x_1;
				x_1 = x_0- (f(x_0) / p(x_0));
				x_1 = x_2;
				x_2 = x_1 - (f(x_1) / p(x_1));
				i++;
				cout << "Ітерація " << i << ": " << "\t" << "x_0 = " << x_0 << endl;
			}
			cout << "\nКількість ітерацій i = " << i << "\n"; // виводимо кількість ітерацій і 
			cout << "\nКорінь x = " << x_2 << " на ітерації " << i << endl;
			return x_2;
	}
	else
	{
		cout << "Коренів не існує" << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}


//#include <iostream>
//#include <cmath>
//#include <Windows.h>
//using namespace std;
//
//// фунція, яка містить рівняння log10(x) + x - 0.5
//double f(double x)
//{ 
//	return log10(x) + x - 0.5;
//}
//
//// похідна від 0.5 - log10(x) = 1 / x * ln(10)
//double p(double x) 
//{
//  return 1 / x * (log10(10) / log10(exp(x))); // 1 / x * ln(10)
//}
//
//int main()
//{
//	// підключення укр.мови 
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	double a = 0.5, b = 1, e = 0.0001; // відрізок [a, b] та задана точність 
//
//	cout << "Інтервал (a, b): " << "(" << a << "," << b << ")" << endl;
//	cout << "Задана точність e = " << e << "\n\n";
//
//	double x;
//	int i = 0; // кількість ітерацій
//	if (f(a) * f(b) < 0)
//	{
//		// якщо |b-a|<e, то x=(b+a)/2 і виводимо повідомлення про кількість ітерацій
//		if (abs(b - a) < e)
//		{
//			x = (b + a) / 2.0;
//			cout << "Кількість ітерацій i =" << i << endl;
//		}
//		else
//		{
//			// заміна a на b
//			if (f(b) * p(b) > 0)
//			{
//				double temp = a;
//				a = b;
//				b = temp;
//			}
//			while (1)
//			{
//				// рівняння дотичної
//				x = b - (f(b) / p(b));
//				i++; // збільш. лічильник операцій
//				cout << "Ітерація " << i << ": " << "\t";
//
//				// якщо |x-a|<e, то x знайдено, інакше a = x
//				if (abs(x - b) < e)
//				{
//					cout << "\nКількість ітерацій i = " << i << "\n"; // виводимо кількість ітерацій і 
//					return x;
//				}
//				else
//				{
//					b = x;
//				}
//				cout << "x = " << x << "\n"; // виводимо x
//			}
//		}
//	}
//	else
//	{
//		cout << "Коренів не існує" << endl;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}







//#include <iostream>
//#include <cmath>
//#include <Windows.h>
//using namespace std;
//
//// фунція, яка містить рівняння log10(x) + x - 0.5
//double f(double x)
//{ 
//	return log10(x) + x - 0.5;
//}
//
//// похідна від 0.5 - log10(x) = 1 / x * ln(10)
//double p(double x) 
//{
//  return 1 / x * (log10(10) / log10(exp(x))); // 1 / x * ln(10)
//}
//
//int main()
//{
//	// підключення укр.мови 
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	double a = 0.5, b = 1, e = 0.0001; // відрізок [a, b] та задана точність 
//
//	cout << "Інтервал (a, b): " << "(" << a << "," << b << ")" << endl;
//	cout << "Задана точність e = " << e << "\n\n";
//
//	double x;
//	int i = 0; // кількість ітерацій
//	if (f(a) * f(b) < 0)
//	{
//		// якщо |b-a|<e, то x=(b+a)/2 і виводимо повідомлення про кількість ітерацій
//		if (abs(b - a) < e)
//		{
//			x = (b + a) / 2.0;
//			cout << "Кількість ітерацій i =" << i << endl;
//		}
//		else
//		{
//			// заміна a на b
//			if (f(b) * p(b) > 0)
//			{
//				double temp = a;
//				a = b;
//				b = temp;
//			}
//			while (1)
//			{
//				// рівняння дотичної
//				x = b - (f(b) / p(b));
//				i++; // збільш. лічильник операцій
//				cout << "Ітерація " << i << ": " << "\t";
//
//				//cout << "b = " << b << "\t"; // виводимо b
//				//cout << "Похідна = " << p(b) << "\t"; // виводимо похідну від b
//
//				// якщо |x-a|<e, то x знайдено, інакше a = x
//				if (abs(x - b) < e)
//				{
//					cout << "\nКількість ітерацій i = " << i << "\n"; // виводимо кількість ітерацій і 
//					return x;
//				}
//				else
//				{
//					b = x;
//				}
//				cout << "x = " << x << "\n"; // виводимо x
//			}
//		}
//	}
//	else
//	{
//		cout << "Коренів не існує" << endl;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//
//
