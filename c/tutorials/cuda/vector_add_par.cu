#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <sys/wait.h>

#define N 2000000000
#define MAX_ERR 1e-8


__global__ void vector_add(float *out, float *a, float *b, long int n)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < n)
    {
    
        // Calculate pi
        int r[2800 + 1];
        int i;
        long int k;
        int e, d;
        for (i = 0; i < 2800; i++) {
            r[i] = 2000;
        }
        for (k = 9000000000000000000; k > 0; k -= 14) {
            d = 0;
            i = k;
            for (;;) {
                d += r[i] * 10000;
                e = 2 * i - 1;
    
                r[i] = d % e;
                d /= e;
                i--;
                if (i == 0) break;
                d *= i;
            }
            float x = d % 10000;
        }

        // Calculate a big factorial
        long int number = 9000000000000000000;
        int fact = 1;    
        for(long int y = 1; y <= number; y++)
        {    
            fact = fact * y;
            long int woo = fact + fact;
            woo *= 2;
            woo *= 2;
            woo *= 2;
            woo *= 2;
            woo *= 2;
            woo *= woo;
            
            woo += woo;            
        }    

        // Do whatever this is
        float ta = a[tid];
        float tb = b[tid];
        ta *= tb + ta;
        
        ta = ta * 2 + tb * 5;
        tb = tb * 5 + tb * 2;
        out[tid] = ta + tb;
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

    #pragma omp parallel for num_threads(N)
    for (int i = 0; i < N; i++)
    {
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    printf("Allocating device memory...\n");
    cudaMalloc((void**)&da, sizeof(float) * N);
    cudaMalloc((void**)&db, sizeof(float) * N);
    cudaMalloc((void**)&dout, sizeof(float) * N);    

    printf("Transferring data to device memory...\n");
    cudaMemcpy(da, a, sizeof(float) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(db, b, sizeof(float) * N, cudaMemcpyHostToDevice);

    printf("Adding vectors...\n");
    int block_size = 16;
    int grid_size = ((N + block_size) / block_size);
    vector_add<<<grid_size, block_size>>>(dout, da, db, N);

    printf("Transferring data back to host memory...\n");
    cudaMemcpy(out, dout, sizeof(float) * N, cudaMemcpyDeviceToHost);

    // Verify output
//    for (int i = 0; i < N; i++)
  //  {
    //    assert(fabs(out[i] - a[i] - b[i]) < MAX_ERR);
    //}
    //printf("PASSED\n");

    printf("Deallocating device memory...\n");
    cudaFree(da);
    cudaFree(db);
    cudaFree(dout);

    printf("Deallocating host memory...\n");
    free(a);
    free(b);
    free(out);

}
