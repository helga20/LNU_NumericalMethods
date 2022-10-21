#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

// ������, ��� ������ ������� log10(x) +x-0.5
double f(double x)
{
	return log10(x) + x - 0.5;
}

// ������� �� log10(x)+x-0.5
double p(double x)
{
	return (1 / x * (log10(10) / log10(exp(x))) + 1); // (1/x*ln(10))+1
}

// ����� ������� �� log10(x)+x-0.5
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

	double x, x_0, x_1, x_2, k;
	int i = 0; // ������� ��������
	if (f(a) * f(b) < 0)
	{
			// ����� a �� b
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
				cout << "�������� " << i << ": " << "\t" << "x_0 = " << x_0 << endl;
			}
			cout << "\nʳ������ �������� i = " << i << "\n"; // �������� ������� �������� � 
			cout << "\n����� x = " << x_2 << " �� �������� " << i << endl;
			return x_2;
	}
	else
	{
		cout << "������ �� ����" << endl;
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
//// ������, ��� ������ ������� log10(x) + x - 0.5
//double f(double x)
//{ 
//	return log10(x) + x - 0.5;
//}
//
//// ������� �� 0.5 - log10(x) = 1 / x * ln(10)
//double p(double x) 
//{
//  return 1 / x * (log10(10) / log10(exp(x))); // 1 / x * ln(10)
//}
//
//int main()
//{
//	// ���������� ���.���� 
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	double a = 0.5, b = 1, e = 0.0001; // ������ [a, b] �� ������ ������� 
//
//	cout << "�������� (a, b): " << "(" << a << "," << b << ")" << endl;
//	cout << "������ ������� e = " << e << "\n\n";
//
//	double x;
//	int i = 0; // ������� ��������
//	if (f(a) * f(b) < 0)
//	{
//		// ���� |b-a|<e, �� x=(b+a)/2 � �������� ����������� ��� ������� ��������
//		if (abs(b - a) < e)
//		{
//			x = (b + a) / 2.0;
//			cout << "ʳ������ �������� i =" << i << endl;
//		}
//		else
//		{
//			// ����� a �� b
//			if (f(b) * p(b) > 0)
//			{
//				double temp = a;
//				a = b;
//				b = temp;
//			}
//			while (1)
//			{
//				// ������� �������
//				x = b - (f(b) / p(b));
//				i++; // �����. �������� ��������
//				cout << "�������� " << i << ": " << "\t";
//
//				// ���� |x-a|<e, �� x ��������, ������ a = x
//				if (abs(x - b) < e)
//				{
//					cout << "\nʳ������ �������� i = " << i << "\n"; // �������� ������� �������� � 
//					return x;
//				}
//				else
//				{
//					b = x;
//				}
//				cout << "x = " << x << "\n"; // �������� x
//			}
//		}
//	}
//	else
//	{
//		cout << "������ �� ����" << endl;
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
//// ������, ��� ������ ������� log10(x) + x - 0.5
//double f(double x)
//{ 
//	return log10(x) + x - 0.5;
//}
//
//// ������� �� 0.5 - log10(x) = 1 / x * ln(10)
//double p(double x) 
//{
//  return 1 / x * (log10(10) / log10(exp(x))); // 1 / x * ln(10)
//}
//
//int main()
//{
//	// ���������� ���.���� 
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	double a = 0.5, b = 1, e = 0.0001; // ������ [a, b] �� ������ ������� 
//
//	cout << "�������� (a, b): " << "(" << a << "," << b << ")" << endl;
//	cout << "������ ������� e = " << e << "\n\n";
//
//	double x;
//	int i = 0; // ������� ��������
//	if (f(a) * f(b) < 0)
//	{
//		// ���� |b-a|<e, �� x=(b+a)/2 � �������� ����������� ��� ������� ��������
//		if (abs(b - a) < e)
//		{
//			x = (b + a) / 2.0;
//			cout << "ʳ������ �������� i =" << i << endl;
//		}
//		else
//		{
//			// ����� a �� b
//			if (f(b) * p(b) > 0)
//			{
//				double temp = a;
//				a = b;
//				b = temp;
//			}
//			while (1)
//			{
//				// ������� �������
//				x = b - (f(b) / p(b));
//				i++; // �����. �������� ��������
//				cout << "�������� " << i << ": " << "\t";
//
//				//cout << "b = " << b << "\t"; // �������� b
//				//cout << "������� = " << p(b) << "\t"; // �������� ������� �� b
//
//				// ���� |x-a|<e, �� x ��������, ������ a = x
//				if (abs(x - b) < e)
//				{
//					cout << "\nʳ������ �������� i = " << i << "\n"; // �������� ������� �������� � 
//					return x;
//				}
//				else
//				{
//					b = x;
//				}
//				cout << "x = " << x << "\n"; // �������� x
//			}
//		}
//	}
//	else
//	{
//		cout << "������ �� ����" << endl;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//
//
