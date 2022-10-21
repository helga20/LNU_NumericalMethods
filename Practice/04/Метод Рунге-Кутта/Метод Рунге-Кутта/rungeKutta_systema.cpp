#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y, double z)
{
	return 2 * z - 3 * y;
}

double g(double x, double y, double z)
{
	return z - 2 * y;
}

double y_func(double x)
{
	return 2 * (1 + x) * exp(-x);
}

double z_func(double x)
{
	return  (3 + 2 * x) * exp(-x);
}

void RungeKut(double a, double b, double h)
{
	double xi = a;
	double yi = 2;
	double zi = 3;
	double delta_y = 0, delta_z = 0;
	double k1 = 0, k2 = 0;
	double l1 = 0, l2 = 0;
	int i = 0;
	double y_s = 0;
	double z_s = 0;
	double y_iplus1 = 0;
	double z_iplus1 = 0;

	while (xi <= b)
	{
		k1 = h * f(xi, yi, zi);
		l1 = h * g(xi, yi, zi);
		k2 = h * f(xi + h, yi + k1, zi + l1);
		l2 = h * g(xi + h, yi + k1, zi + l1);
		y_iplus1 = yi + ((k1 + k2) / 2);
		z_iplus1 = zi + ((l1 + l2) / 2);
		y_s = y_func(xi);
		z_s = z_func(xi);
		delta_y = y_s - y_iplus1;
		delta_z = z_s - z_iplus1;
		cout << "xi [" << i << "] = " << xi << "\t yi = [" << i << "] = " << y_iplus1 << "\t zi = [" << i << "] = " << z_iplus1;
		cout << "\t y* = [" << i << "] = " << y_s << "\t z* = [" << i << "] = " << z_s;
		cout << "\t   delta_y = " << delta_y << "\t   delta_z = " << delta_z << '\n';
		xi += h;
		yi += h;
		zi += h;
		++i;
	}

}
int main()
{
	double a = 0, b = 0.1, h = 0.01;
	cout << "Method Runge-Kutta:\n";
	RungeKut(a, b, h);

	cout << "\n";
	system("pause");
	return 0;
}