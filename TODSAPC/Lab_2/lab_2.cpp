#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;
using vectr = vector<double>;
using matrix = vector<vector<double>>;
const int cores_count = 10;

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

matrix gen_matrix(int n)
{
    matrix m(n, vectr(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = rand() % 20 - 10;
        }
    }
    return m;
}

double calc_norm(const vectr& row)
{
    double norm = 0.0;
    for (double value: row)
    {
        norm += abs(value);
    }
    return norm;
}

Result calc_row_norms(const matrix& m)
{
    int n = m.size();
    Result result(n);
    double start_time = omp_get_wtime();
    for (int i = 0; i < n; i++)
    {
        result.vector[i] = calc_norm(m[i]);
    }
    double end_time = omp_get_wtime();
    result.time = end_time - start_time;
    cout << "Total time of " << n << "*" << n << " matrix's row norms calculating: " << result.time << " seconds." << endl;
    return result;
}

Result paral_calc_row_norms(const matrix& m, const string& schedule, int chunk)
{
    int n = m.size();
    Result result(n); 

    double start_time = omp_get_wtime();
    
    if (schedule == "Dynamic") 
    {
        cout << "Dynamic schedule(" << chunk << ")" << endl;
        #pragma omp parallel for schedule(dynamic, chunk)
        for (int i = 0; i < n; i++) 
        {
            result.vector[i] = calc_norm(m[i]);
            #pragma omp critical
            {
                int thread_num = omp_get_thread_num();
                cout << "Thread " << thread_num << " calculated " << i << " row." << endl;
            }
        }
    }
    else if (schedule == "Guided") 
    {
        cout << "Guided schedule(" << chunk << ")" << endl;
        #pragma omp parallel for schedule(guided, chunk)
        for (int i = 0; i < n; i++) 
        {
            result.vector[i] = calc_norm(m[i]);
            #pragma omp critical
            {
                int thread_num = omp_get_thread_num();
                cout << "Thread " << thread_num << " calculated " << i << " row." << endl;
            }
        }
    }
    else {
        cout << "Invalid schedule type." << endl;
        return result;
    }

    double end_time = omp_get_wtime();
    result.time = end_time - start_time;
    cout << endl << "Total time of " << n << "*" << n << " matrix's row norms calculating: " << result.time << " seconds." << endl;
    return result;
}

void print_row_norms(const vectr& norms)
{
    int i = 0;
    for (double norm : norms)
    {
        cout << "Row " << ++i << " norm: " << norm << endl;
    }
    cout << endl;
}

void print_matrix(const matrix& m)
{
    for (const auto& row : m)
    {
        for (const double value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
    cout << endl;
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
    srand(time(nullptr));

    const vectr n = {10};
    const vectr threads = {2};
    const string DYNAMIC = "Dynamic";
    const string GUIDED = "Guided";

    for(int num : n)
    {
        matrix A = gen_matrix(num);
        matrix B = gen_matrix(num);
        cout << "----- Matrix A -----" << endl;
        print_matrix(A);
        cout << "----- Matrix B -----" << endl;
        print_matrix(B);
    
        cout << "----- Sequential calculating -----" << endl;
        Result C = calc_row_norms(A);
        Result D = calc_row_norms(B);
        double c_time = C.time;
        double d_time = D.time;
        cout << "----- Matrix A row norms -----" << endl;
        print_row_norms(C.vector);
        cout << "----- Matrix B row norms -----" << endl;
        print_row_norms(D.vector);
        
        cout << "----- Parallel calculating -----" << endl;
        for(int thread: threads)
        {
            double speedup, efficiency = 0.0;
            cout << "Threads count: " << thread << endl;
            omp_set_num_threads(thread); 
            C = paral_calc_row_norms(A, DYNAMIC, 6);
            speedup = calc_speedup(c_time, C.time);
            efficiency = calc_efficiency(speedup);
            cout << "Parallel speedup: " << speedup << endl;        
            cout << "Parallel efficiency: " << efficiency << endl;

            D = paral_calc_row_norms(B, GUIDED, 4);
            speedup = calc_speedup(d_time, D.time);
            efficiency = calc_efficiency(speedup);
            cout << "Parallel speedup: " << speedup << endl;        
            cout << "Parallel efficiency: " << efficiency << endl;
            cout << "----- Matrix A row norms -----" << endl;
            print_row_norms(C.vector);
            cout << "----- Matrix B row norms -----" << endl;
            print_row_norms(D.vector);
        }
    }
}