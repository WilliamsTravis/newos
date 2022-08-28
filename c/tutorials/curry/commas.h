#include <iostream>
#include <string>

using namespace std;


string commas(long long n) 
{
    string s;
    int count = 0;
    do
    {
        s.insert(0, 1, char('0' + n % 10));
        n /= 10;
        if (++count == 3 && n)
        {
            s.insert(0, 1, ',');
            count = 0;
        }
    } while (n);

    return s;
}
