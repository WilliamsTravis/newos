#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;


int main()
{

    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string pw = "password";
    string guess;
    do
    {
        cout << "Enter password:";
        cin >> guess;
        cout << "\n";
    }while(guess != pw);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    cout << "\nLogin sucessful." << endl;

    return 0;
}