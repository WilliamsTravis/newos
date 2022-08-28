#include <iostream>
#include <string>
#include <string.h>
#include <list>


int test_one()
{
    // c++ style strings
    std::string check = "Test two three...";
    for (int i = 0; i <= check.length(); i++){
        std::cout << check[i] << std::endl;
    }

    // Can't do the same with c style strings
    char check2[] = "Test three four...";
    for (int i = 0; i <= strlen(check2); i++){
        std::cout << check2[i] << std::endl;
    }

    return 0;
}


int test_two()
{
    // Get user input string
    std::string check4;
    std::cout << "Enter another string: \n";
    getline(std::cin, check4);
    std::cout << "You entered: " + check4 << std::endl;

    return 0;
}


int test_three()
{
    std::string greeting = "hello";
    greeting += " there!";
    greeting.insert(0, "Well, ");
    greeting.erase(0, 6);
    greeting.erase(greeting.length() - 1, 1);
    greeting.pop_back();
    greeting.replace(6, 4, "there!");
    std::cout << greeting << std::endl;

    return 0;
}


int censor()
{

    std::list<std::string> curses = {"hell", "shit", "fuck", "damn", "crap"};

    std::string user_curses;
    std::cout << "Enter a curse: \n";
    getline(std::cin, user_curses);

    for (std::string c : curses) {
        int where = user_curses.find(c);
        if (where != -1) {
            user_curses.replace(where, c.size(), "****");
        }
    }

    std::cout << user_curses << std::endl;

    return 0;
}


int main()
{
    // test_one();
    // test_two();
    // test_three();
    censor();

    return 0;
}
