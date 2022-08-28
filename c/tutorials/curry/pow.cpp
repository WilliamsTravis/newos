#include <iostream>
#include <cmath>
#include "commas.h"

using std::cout;
using std::cin;


double power(double base, int exponent)
{
    double result = 1;
    for(int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}


void print_power(double base, int exponent)
{
    double p = power(base, exponent);
    cout << commas(base) << " raised to the " << commas(exponent) << " power is " << commas(p) << "\n";
}


int main()
{
    double base;
    int exponent;
    cout << "Base: ";
    cin >> base;
    cout << "Exponent: ";
    cin >> exponent;
    print_power(base, exponent);
    return 0;
}
