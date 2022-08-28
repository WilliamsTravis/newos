#include <iostream>
#include <string>
#include "commas.h"


int main()
{
    long long factorial;
    std::cin >> factorial;
    long long original = factorial;
    for (long long i = factorial - 1; i > 0; i--)
    {
        factorial *= i;
    }

    
    while (y > 0)
    {
        std::cout << y << std::endl;
        y++;
    }


    std::cout << "Input value: " << commas(original) << std::endl;
    std::cout << "Factorial: " << commas(factorial) << std::endl;

    return 0;
}