#include <iostream>
#include <chrono>
#include "commas.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std::chrono;


int main()
{
    // Start timer
    auto start = high_resolution_clock::now();

    // branching
    int x;
    cin >> x;
    if (x == 10)
    {
        cout << "Exactly!" << endl;       
    }
    else if (x == 11 || x == 9)
    {
        cout << "Close" << endl;
    }
    else
    {
        cout << "Wrong!" << endl;
    }

    auto end = high_resolution_clock::now();
    auto ms = duration_cast<microseconds>(end - start);
    cout << "Runtime: " << commas(ms.count()) << "ms" << endl;

    return 0;   
}