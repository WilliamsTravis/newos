#include <string>
#include <iostream>
#include <limits>
#include <array>

using namespace std;

void parray(array<int, 10> &data){
    // Print Array Size
    int size = data.size();
    std::cout << size << " elements" << std::endl;

    // Print Array
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i];
        if (i < size - 1){
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}


int main()
{
    array<int, 10> data;
    for (int i = 0; i < data.size(); i++)
    {
        data[i] = i;
    }
    parray(data);

    // Input is still live
    // std::cin.clear();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // std::string test;
    // std::cin >> test;
    // std::cout << test << std::endl;

    return 0;
}