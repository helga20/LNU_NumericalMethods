//#include <iostream>
//#include<math.h>  
//using namespace std;
//double f(double x)
//{
//	return exp(x) * sin(2 * x);
//}
//
//double Rectangle(double a, double b, int n)
//{
//
//	double s = 0, k = 0, i = a;
//	double h = (b - a) / n;
//	while (i < b)
//	{
//		k = (h)*f((2 * i + h) / 2.0);
//		i += h;
//		s += k;
//	}
//	return s;
//}
//
//double Trapezia(double a, double b, int n)
//{
//	double h = (b - a) / n;
//	double s = 0;
//	for (int i = 0; i < n; i++)
//	{
//		double x1 = a + i * h;
//		double x2 = a + (i + 1) * h;
//		s += 0.5 * (x2 - x1) * (f(x1) + f(x2));
//	}
//
//	return s;
//}
//
//double Sympson(double a, double b, int n)
//{
//	double h = (b - a) / n;
//	double x = a;
//	double s = 0.5 * f(x) + 0.5 * f(a + n * h);
//	for (int i = 1; i < n;i++)
//	{
//		s += f(a + i * h);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		s += 2 * f((a + (i - 1) * h + a + i * h) / 2);
//	}
//	s *= h / 3;
//	return s;
//}
//
//float ThreeEights(double a, double b, int n)
//{
//	double h = (b - a)/ n;
//	double s = f(a) + f(b);
//
//	for (int i = 1; i < n; i++)
//	{
//		if (i % 3 == 0)
//		{
//			s = s + 2 * f(a + i * h);
//		}
//		else
//		{
//			s = s + 3 * f(a + i * h);
//		}
//	}
//	return (3 * h / 8) * s;
//}
//
//double Newton_Leibniz(double a, double b)
//{
//	double x = 0;
//	x = (exp(b) / 5) * (sin(2 * b) - 2 * cos(2 * b)) - (exp(a) / 5) * (sin(2 * a) - 2 * cos(2 * a));
//	return x;
//}
//
//int main()
//{
//	double a = 2.0, b = 3.0, eps = 0.00001, n = 5;
//	cout << "Rectangles method = " << Rectangle(a, b, n) << '\n';
//	cout << "\Trapezia method = " << Trapezia(a, b, n) << '\n';
//	cout << "\Sympson method = " << Sympson(a, b, n) << '\n';
//	cout << "\Method of three eighths = " << ThreeEights(a, b, n) << '\n';
//	cout << "Newton Leibniz formula = " << Newton_Leibniz(a, b) << endl;
//
//	cout << '\n';
//	system("pause");
//	return 0;
//}


#include <iostream>
#include<math.h>  
using namespace std;
double f(double x)
{
	return (-pow(x, 2) + 2 * x + 3);
}

double Rectangle(double a, double b, int n)
{

	double s = 0, k = 0, i = a;
	double h = (b - a) / n;
	while (i < b)
	{
		k = (h)*f((2 * i + h) / 2.0);
		i += h;
		s += k;
	}
	return s;
}

double Trapezia(double a, double b, int n)
{
	double h = (b - a) / n;
	double s = 0;
	for (int i = 0; i < n; i++)
	{
		double x1 = a + i * h;
		double x2 = a + (i + 1) * h;
		s += 0.5 * (x2 - x1) * (f(x1) + f(x2));
	}

	return s;
}

double Sympson(double a, double b, int n)
{
	double h = (b - a) / n;
	double x = a;
	double s = 0.5 * f(x) + 0.5 * f(a + n * h);
	for (int i = 1; i < n; i++)
	{
		s += f(a + i * h);
	}
	for (int i = 1; i <= n; i++)
	{
		s += 2 * f((a + (i - 1) * h + a + i * h) / 2);
	}
	s *= h / 3;
	return s;
}

float ThreeEights(double a, double b, int n)
{
	double h = (b - a) / n;
	double s = f(a) + f(b);

	for (int i = 1; i < n; i++)
	{
		if (i % 3 == 0)
		{
			s = s + 2 * f(a + i * h);
		}
		else
		{
			s = s + 3 * f(a + i * h);
		}
	}
	return (3 * h / 8) * s;
}

double Newton_Leibniz(double a, double b)
{
	double x = 0;
	x = (exp(b) / 5) * (sin(2 * b) - 2 * cos(2 * b)) - (exp(a) / 5) * (sin(2 * a) - 2 * cos(2 * a));
	return x;
}

int main()
{
	double a = -1.0, b = 3.0, eps = 0.00001, n = 4;
	cout << "Rectangles method = " << Rectangle(a, b, n) << '\n';
	cout << "\Trapezia method = " << Trapezia(a, b, n) << '\n';
	cout << "\Sympson method = " << Sympson(a, b, n) << '\n';
	cout << "\Method of three eighths = " << ThreeEights(a, b, n) << '\n';
	cout << "Newton Leibniz formula = " << Newton_Leibniz(a, b) << endl;

	cout << '\n';
	system("pause");
	return 0;
}