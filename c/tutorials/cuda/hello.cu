#include <stdio.h>


__global__ void what()
{
    printf("Hello World, speaking from your GPU!\n");
}

int main()
{
    what<<<1,1>>>();

    return 0;
}
