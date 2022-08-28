# include <iostream>
// find operator precedence here: 
// https://en.cppreference.com/w/cpp/language/operator_precedence

int main()
{
    double x = 10 * 4 * 3;
    std::cout << x << std::endl;

    double y;
    double z;
    y = 10;
    (z = y) = 100;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}