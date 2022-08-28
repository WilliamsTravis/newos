#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

void game()
{
    int random = rand() % 251;
    std::cout << "We're playing! The game is called 'Just a Random Number!'\n";
    sleep(2);
    std::cout << "Your random number is " << random << "!\n";
    sleep(2);
    std::cout << "What now?\n\n";
}

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "0. Quit" << std::endl << "1. Play Game\n";
        std::cin >> choice;

        switch(choice)
        {
            case 0:
                std::cout << "Thanks for playing.\n";
                return 0;
            case 1:
                game();
                break;
        }
    }
    while(choice != 0);

}