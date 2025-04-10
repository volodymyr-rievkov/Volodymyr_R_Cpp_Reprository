#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <cuda_runtime.h>

using namespace std;

struct Point {
    double x = 0.0;
    double y = 0.0;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

vector<Point> gen_convex_polygon(int N, double radius = 5.0) {
    if (N < 3) {
        return vector<Point>();
    }

    std::vector<Point> points;
    const double TWO_PI = 2.0 * M_PI;

    for (int i = 0; i < N; i++) {
        double theta = TWO_PI * i / N;
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        points.emplace_back(x, y);
    }

    return points;
}

double calc_area_cpu(const vector<Point> &vertices) {
    auto start_time = chrono::high_resolution_clock::now();
    double area = 0.0;
    int n = vertices.size();

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += vertices[i].x * vertices[next].y;
        area -= vertices[next].x * vertices[i].y;
    }
    area = abs(area) / 2.0;

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end_time - start_time;
    cout << "----- CPU Calculation -----" << endl;
    cout << "Area: " << area << endl;
    cout << "\033[33mTotal time: " << time.count() << "s.\033[0m" << endl;
    return time.count();
}

__device__ double calc_area_part(double cur_x, double cur_y, double next_x, double next_y) {
    return cur_x * next_y - next_x * cur_y;
}

__global__ void area_gpu_kernel(const Point* d_points, double* d_area, int n) {
    extern __shared__ double shared_area[]; 

    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    int tid = threadIdx.x;
    double partial_area = 0.0;

    if (idx < n) {
        int next = (idx + 1) % n;
        partial_area = calc_area_part(d_points[idx].x, d_points[idx].y, 
                                     d_points[next].x, d_points[next].y);
    }

    shared_area[tid] = partial_area;
    __syncthreads();

    for (int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
        if (tid < stride && (tid + stride + blockIdx.x * blockDim.x) < n) {
            shared_area[tid] += shared_area[tid + stride];
        }
        __syncthreads();
    }

    if (tid == 0) {
        atomicAdd(d_area, shared_area[0]);
    }
}

double calc_area_gpu(const vector<Point> &points) { 
    int n = points.size();
    Point *d_points;
    double *d_area;
    double area = 0.0;

    cudaMalloc((void**)&d_points, n * sizeof(Point));
    cudaMalloc((void**)&d_area, sizeof(double));

    cudaMemcpy(d_points, points.data(), n * sizeof(Point), cudaMemcpyHostToDevice);
    cudaMemset(d_area, 0, sizeof(double));
    
    auto start_time = chrono::high_resolution_clock::now();

    const int block_size = 256;
    const int num_blocks = (n + block_size - 1) / block_size;
    size_t shared_mem_size = block_size * sizeof(double);
    area_gpu_kernel<<<num_blocks, block_size, shared_mem_size>>>(d_points, d_area, n);

    cudaDeviceSynchronize();
    cudaMemcpy(&area, d_area, sizeof(double), cudaMemcpyDeviceToHost);

    cudaFree(d_points);
    cudaFree(d_area);

    area = abs(area) / 2.0;

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> time = end_time - start_time;
    cout << "----- GPU Calculation -----" << endl;
    cout << "Area: " << area << endl;
    cout << "\033[33mTotal time: " << time.count() << "s.\033[0m" << endl;
    return time.count();
}

double calc_speedup(double cpu, double gpu) {
    double speedup = cpu / gpu;
    cout << "\033[34mGPU speedup: " << speedup << "\033[0m" << endl;
    return speedup;
}

int main() {
    const double N = 13;
    const vector<double> Ns = {N * 1e5, N * 1e6, N * 1e7};

    for (const double n : Ns) {
        cout << "----- N: " << n << " -----" << endl;
        vector<Point> convex_polygon = gen_convex_polygon(n);
        double cpu_time = calc_area_cpu(convex_polygon);

        double gpu_time = calc_area_gpu(convex_polygon);
        double speedup = calc_speedup(cpu_time, gpu_time);
    }
}