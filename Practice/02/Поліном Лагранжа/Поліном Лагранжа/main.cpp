#include <iostream>
using namespace std;

const int n = 6; 

double lagranz(double x[n], double y[n], double x_0);

int main() 
{
    double x[n] = { 1000, 1010, 1020, 1030, 1040, 1050 };
    double y[n] = { 3.00000, 3.00432, 3.00860, 3.01254, 3.01703, 3.02119 };
    cout << "L(1015)=" << lagranz(x, y, 1015) << " " << endl;
    cout << "L(1045)=" << lagranz(x, y, 1045) << " " << endl;
    return 0;
}

double lagranz(double x[n], double y[n], double x_0)
{
    double sum, prod;
    sum = 0;
    for (int j = 0; j < n; j++)
    {
        prod = 1;
        for (int i = 0; i < n; i++) 
        {
            if (i != j) 
            {
                prod = prod * (x_0 - x[i]) / (x[j] - x[i]);
            }
        }
        sum = sum + y[j] * prod;
    }
    return sum;
}

