#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <cuda_runtime.h>

using namespace std;

double func_cpu(double x, double a, double z)
{
    double denom = a - 2 * x;
    if(fabs(denom) < 1e-10) return 0.0;
    return (cos(x) / denom) + (16 * x * cos(x * z) - 2);
}

__device__ double func_gpu(double x, double a, double z)
{
    double denom = a - 2 * x;
    if(fabs(denom) < 1e-10) return 0.0;
    return (cos(x) / denom) + (16 * x * cos(x * z) - 2);
}

__global__ void kernel_gpu(double *d_result, double a, double z, double x_start, double x_end, double h)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    double x = x_start + idx * h;

    if (x <= x_end) {
        double result = func_gpu(x, a, z);
        atomicAdd(d_result, result);  
    }
}

double cpu_calculation(double x_start, double x_end, double a, double z, double h)
{
    auto start_time = chrono::high_resolution_clock::now();
    double result = 0.0;
    for (double x = x_start; x <= x_end; x += h)
    {
        result += func_cpu(x, a, z);
    }
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end_time - start_time;
    cout << "----- CPU Calculation -----" << endl;
    cout << "Result: " << result << endl;
    cout << "\033[33mTotal time: " << time.count() << "s.\033[0m" << endl;
    return time.count();
}

double gpu_calculation(double x_start, double x_end, double a, double z, double h)
{
    double *d_result;
    cudaMalloc((void**)&d_result, sizeof(double));
    cudaMemset(d_result, 0, sizeof(double));  

    const int block_size = 256;  
    const int num_blocks = ceil((x_end - x_start) / h / block_size); 

    auto start_gpu_time = chrono::high_resolution_clock::now();
    kernel_gpu<<<num_blocks, block_size>>>(d_result, a, z, x_start, x_end, h);
    cudaDeviceSynchronize();
    auto end_gpu_time = chrono::high_resolution_clock::now();

    double gpu_result;
    cudaMemcpy(&gpu_result, d_result, sizeof(double), cudaMemcpyDeviceToHost);  
    chrono::duration<double> gpu_time = end_gpu_time - start_gpu_time;

    cudaFree(d_result);


    cout << "----- GPU Calculation -----" << endl;
    cout << "Result: " << gpu_result << endl;
    cout << "\033[33mTotal time: " << gpu_time.count() << "s.\033[0m" << endl;

    return gpu_time.count();
}

double calc_speedup(double cpu, double gpu)
{
    double speedup = cpu / gpu;
    cout << "\033[34mGPU speedup: " << speedup << "\033[0m" << endl;
    return speedup;
}

int main()
{
    const double N = 13;
    const vector<double> Ns = {N * 1e5, N * 1e6, N * 1e7};

    for (const double n : Ns)
    {
        cout << "----- N: " << n << " -----" << endl;        

        double a = n;
        double z = pow(n, 2);
        double k = n / 2;
        double h = n / k;
        double x_start = 1.0;
        double x_end = n + 1.0;

        double cpu_time = cpu_calculation(x_start, x_end, a, z, h);
        double gpu_time = gpu_calculation(x_start, x_end, a, z, h);
        double speedup = calc_speedup(cpu_time, gpu_time);
    }    
}
