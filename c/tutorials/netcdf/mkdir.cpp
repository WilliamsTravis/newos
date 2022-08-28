// C++ program to create a directory in Linux
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
  
int main() 
{
    // Creating a directory
    if (mkdir("outputs", 0777) == -1)
        cerr << "Error :  " << strerror(errno) << endl;
  
    else
        cout << "Directory created" << endl;
}