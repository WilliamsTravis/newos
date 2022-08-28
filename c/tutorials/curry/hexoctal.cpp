#include <iostream>
#include <string>

int main()
{
    // Base 10 is not the only way
    // It seems like God made it such that 10 was the only way
    // But it's not, and He didn't
    int dec = 30;
    int hex = 0x30; // 48
    int oct = 030;
    std::cout << std::hex << "30 in hexadecimal = " << dec << std::endl;
    std::cout << std::oct << "30 in octadecimal = " << dec << std::endl;
    std::cout << "0x30 in decimal = " << hex << std::endl;
    std::cout << "030 in decimal = " << oct << std::endl;
}