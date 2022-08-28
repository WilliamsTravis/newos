#include <string>
#include <iostream>

int main()
{

    enum class Season{summer, spring, fall, winter};
    Season now = Season::winter;

    // int age;
    // std::cout << "What's your age?: ";
    // std::cin >> age;

    switch(now)
    {
        case Season::summer:
            std::cout << "It's summer!\n";
            break;
        case Season::spring:
            std::cout << "It's spring!\n";
            break;
        case Season::fall:
            std::cout << "It's fall!\n";
            break;
       case Season::winter:
            std::cout << "It's winter!\n";
            break;
    }

    return 0;
}