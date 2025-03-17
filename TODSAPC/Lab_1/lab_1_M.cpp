#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>

using namespace std;
using vectr = vector<double>;
using matrix = vector<vector<double>>;

const vectr n = {1000, 2000, 4000, 8000};
const vectr threads = {1, 5, 10, 15};
const int cores_count = omp_get_max_threads();

struct Result
{
    double time;
    vectr vector;

    Result(int n)
    {
        vector = vectr(n, 0.0);
        time = 0.0;
    }
};

pair<matrix, vectr> generate_matrix_and_vector(int n) 
{
    matrix A(n, vectr(n, 0.0));  
    vectr B(n, 0.0);             

    for (int i = 0; i < n; i++) 
    {
        B[i] = i * sin(i);  
        for (int j = 0; j < n; j++) 
        {
            A[i][j] = j * sin(i);  
        }
    }

    return {A, B};
}

Result seq_matrix_multiply(int n)
{
    Result result(n);
    auto [A, b] = generate_matrix_and_vector(n);
    double start_time = omp_get_wtime();
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            result.vector[j] += A[i][j] * b[j];
        }
    }
    double end_time = omp_get_wtime();
    result.time = end_time - start_time;
    cout << "Total time of sequantial matrix multiplying: " << result.time << " seconds"<< endl;
    return result;
}

Result paral_matrix_multiply(int n, int thread_count) 
{
    Result result(n);
    auto [A, b] = generate_matrix_and_vector(n);
    double start_time = omp_get_wtime();

    #pragma omp parallel for num_threads(thread_count) schedule(dynamic, 100)
    for (int j = 0; j < n; j++)  
    {
        double sum = 0.0;
        #pragma omp simd reduction(+:sum)
        for (int i = 0; i < n; i++)  
        {
            sum += A[i][j] * b[j];  
        }
        
        result.vector[j] = sum;  
    }

    double end_time = omp_get_wtime();
    result.time = end_time - start_time;
    cout << "Total time of parallel matrix multiplication: " << result.time << " seconds" << endl;
    return result;
}

void print_vector(const vectr& vector)
{
    cout << "{ ";
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i];
        if(i < vector.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << " }" << endl;
        }
    }
}

double calc_speedup(double T_s, double T_p)
{
    return T_s / T_p;
}

double calc_efficiency(double speedup)
{
    return speedup / cores_count;
}

int main()
{
    for (double num : n)
    {
        cout << "Matrix capicity " << num << "*" << num << endl;
        for(double thread : threads)
        {
            cout << "Threads count - " << thread << endl;
            Result seq_result = seq_matrix_multiply(num);
            //print_vector(seq_result.vector);
            Result paral_result = paral_matrix_multiply(num, thread);
            //print_vector(paral_result.vector);
            double speedup = calc_speedup(seq_result.time, paral_result.time);
            cout << "Parallel speedup: " << speedup << endl;        
            cout << "Parallel efficiency: " << calc_efficiency(speedup) << endl;
        }
    }
}

