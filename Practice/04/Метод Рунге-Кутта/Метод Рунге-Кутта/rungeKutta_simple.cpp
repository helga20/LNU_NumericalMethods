//#include <iostream>
//#include <cmath>
//using namespace std;
//
//double f(double x, double y)
//{
//	return ((y * (pow(x, 2) - pow(y, 2)) / (2 * pow(x, 3))));
//}
//
//double y_func(double x)
//{
//	return x / sqrt(log(x / 2) + 1);
//}
//
//void RungeKut(double a, double b, double h)
//{
//	double xi = a;
//	double yi = 2;
//	double delta = 0;
//	double k1 = 0, k2 = 0;
//	int i = 0;
//	double y_s = 0;
//	double y_iplus1 = 0;
//
//	while (xi <= b + h)
//	{
//		k1 = h * f(xi, yi);
//		k2 = h * f(xi + h , yi + k1);
//		y_iplus1 = yi + ((k1 + k2) / 2);
//		y_s = y_func(xi);
//		delta = y_s - (yi + ((k1 + k2) / 2));
//		cout << "xi [" << i << "] = " << xi << "\t yi = [" << i << "] = " << y_iplus1 << "\t y* = [" << i << "] = " << y_s << "\t delta = " << delta << '\n';
//		xi += h;
//		++i;
//	}
//
//}
//int main()
//{
//	double a = 2, b = 3.5, h = 0.05;
//	cout << "Method Runge-Kutta:\n";
//	RungeKut(a, b, h);
//
//	cout << "\n";
//	system("pause");
//	return 0;
//}