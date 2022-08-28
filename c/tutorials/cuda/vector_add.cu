#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 10000000
#define MAX_ERR 1e-6


__global__ void vector_add(float *out, float *a, float *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        out[i] = a[i] + b[i];
    }
}

int main()
{
    printf("Initializing host and device variables...\n");
    float *a, *b, *out;
    float *da, *db, *dout;

    printf("Allocating host memory...\n");
    a = (float*)malloc(sizeof(float) * N);
    b = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    printf("Initializing host array...\n");
    for (int i = 0; i < N; i++)
    {
        a[i] = 1.0f; b[i] = 2.0f;
    }

    printf("Allocating device memory...\n");
    cudaMalloc((void**)&da, sizeof(float) * N);
    cudaMalloc((void**)&db, sizeof(float) * N);
    cudaMalloc((void**)&dout, sizeof(float) * N);    

    printf("Transferring data to device memory...\n");
    cudaMemcpy(da, a, sizeof(float) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(db, b, sizeof(float) * N, cudaMemcpyHostToDevice);

    printf("Adding vectors...\n");
    vector_add<<<1,1>>>(dout, da, db, N);

    printf("Transferring data back to host memory...\n");
    cudaMemcpy(out, dout, sizeof(float) * N, cudaMemcpyDeviceToHost);

    // printf("Verifying output...\n");
    // for (int i = 0; i < N; i++)
    // {
    //     assert(fabs(out[i] - a[i] -b[i]) < MAX_ERR);
    // }

    printf("out[0] = %f\n", out[0]);

    printf("Deallocating device memory...\n");
    cudaFree(da);
    cudaFree(db);
    cudaFree(dout);

    printf("Deallocating host memory...\n");
    free(a);
    free(b);
    free(out);
}