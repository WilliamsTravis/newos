#include <stdio.h>
#include <stdlib.h>

#define N 2000000000


void vector_add(float *out, float *a, float *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        out[i] = a[i] + b[i];
    }
}

int main()
{
    printf("Initializing variables...\n");
    float *a, *b, *out;

    printf("Allocating memory...\n");
    a = (float*)malloc(sizeof(float) * N);
    b = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    printf("Initializing array...\n");
    for (int i = 0; i < N; i++)
    {
        a[i] = 1.0f; b[i] = 2.0f;
    }

    printf("Adding vectors...\n");
    vector_add(out, a, b, N);

}