#include <iostream>
#include <fstream>
#include <omp.h>
#include <cmath>
#include <vector>

using namespace std;
using vectr = vector<double>;
const int cores_count = omp_get_max_threads();

struct Result
{
    double time;
    double result = 0.0;
};

double f_1(double x)
{
    return sin(0.5 * x) / pow((2.1 + 3.8 * sin(0.5 * x)), 2);
}

double f_2(double x)
{
    return pow(x, 2) / (x + log(x + 0.22));
}

Result seq_integral_calc(double (*func)(double), double a, double b, double step)
{
    int steps_count = (b - a) / step;
    double x = 0.0;
    Result result;

    double start_time = omp_get_wtime();
    for (int i = 0; i < steps_count; i++)
    {
        x = a + (i + 0.5) * step;
        result.result += func(x);
    }
    result.result *= step;
    double end_time = omp_get_wtime();
    result.time = end_time - start_time;
    cout << "Result: " << result.result << endl;
    cout << "\033[33mTotal time: " << result.time << "\033[0m" << endl;

    return result;
}

Result paral_integral_calc(double (*func)(double), double a, double b, double step, int threads_count, const char* file_name)
{
    int steps_count = (b - a) / step;
    int chunk_size;
    Result result;
    vector<string> messages;
    omp_lock_t file_lock;
    omp_init_lock(&file_lock);

    if (steps_count <= threads_count) 
    {
        chunk_size = 1; 
    } 
    else if (steps_count / threads_count < 100) 
    {
        chunk_size = max(1, steps_count / (threads_count * 2)); 
    } 
    else 
    {
        chunk_size = max(1, steps_count / (threads_count * 10)); 
    }

    double start_time = omp_get_wtime();
    #pragma omp parallel num_threads(threads_count)
    {
        double local_result = 0.0;
        double x = 0.0;
        int thread_id = omp_get_thread_num();

        #pragma omp for schedule(dynamic, chunk_size) 
        for (int i = 0; i < steps_count; i++)
        {
            double x = a + (i + 0.5) * step;
            local_result += func(x);
        }
        
        #pragma omp atomic
        result.result += local_result;

        if (omp_test_lock(&file_lock))
        {
            #pragma omp critical
            {
                messages.push_back("Thread " + to_string(thread_id) + " entered closed section.");
                messages.push_back("Thread " + to_string(thread_id) + " exited closed section.");
                omp_unset_lock(&file_lock);
            }
        }
        else
        {
            #pragma omp critical
            {
                messages.push_back("Thread " + to_string(thread_id) + " failed to enter closed section.");
            }
        }
    }
    omp_destroy_lock(&file_lock);

    result.result *= step;
    double end_time = omp_get_wtime();
    result.time = end_time - start_time;

    ofstream log_file(file_name, ios::app);
    if(log_file.is_open())
    {
        log_file << "----- Threads count: " + to_string(threads_count) + " -----" << endl;
        log_file << "----- Step: " + to_string(step) + " -----" << endl;
        for(const string& msg : messages)
        {
            log_file << msg << endl;
        }
        log_file << "Result: " + to_string(result.result) << endl;
        log_file << "Total time: " + to_string(result.time) << endl;
        log_file.close();
    }

    cout << "Result: " << result.result << endl;
    cout << "\033[33mTotal time: " << result.time << "\033[0m" << endl;

    return result;
}

void write_mesg(const char* filename, const string& message)
{
    #pragma omp parallel
    {
        #pragma omp single
        {
            ofstream file(filename, ios::trunc);
            if(file.is_open())
            {
                file << message;
            }
            file.close();
        }
    }
}

double calc_speedup(double T_s, double T_p)
{
    double speedup = T_s / T_p;
    cout << "\033[34mParallel speedup: " << speedup << "\033[0m" << endl;
    return speedup;
}

double calc_efficiency(double speedup)
{
    double efficiency = speedup / cores_count;
    cout << "\033[32mParallel efficiency: " << efficiency << "\033[0m" << endl;
    return efficiency;
}

int main()
{
    const vectr thread_counts = {1, 5, 10, 15};
    const vectr steps = {2e-5, 2e-6, 2e-7};
    const double a_1 = 1;
    const double b_1 = 2;
    const double a_2 = 2;
    const double b_2 = 3;
    const string message = "Lab №3: Loading and Synchronization in OpenMP.\n"
                            "Group: AI-21.\n"
                            "Rievkov Volodymyr Volodymyrovych.\n"
                            "Option №13.\n"
                            "Task: Multi-thread integral calculation.\n";
    const char* filename_1 = "integral_1_results.txt";
    const char* filename_2 = "integral_2_results.txt";

    write_mesg(filename_1, message);
    write_mesg(filename_2, message);
    for (double step : steps)
    {
        cout << "----- Step " << step << " -----" << endl;
        cout << "Sequenatial integral calculation" << endl;
        //cout << "Integral #1" << endl;
        //Result seq_result_1 = seq_integral_calc(f_1, a_1, b_1, step);
        cout << "Integral #2" << endl;
        Result seq_result_2 = seq_integral_calc(f_2, a_2, b_2, step);

        for (int threads_count : thread_counts)
        {
            cout << "----- Threads count " << threads_count << " -----" << endl;
            cout << "Parallel integral calculation" << endl;            
            //cout << "Integral #1" << endl;
            //Result par_result_1 = paral_integral_calc(f_1, a_1, b_1, step, threads_count, filename_1);
            //calc_efficiency(calc_speedup(seq_result_1.time, par_result_1.time));
            cout << "Integral #2" << endl;
            Result par_result_2 = paral_integral_calc(f_2, a_2, b_2, step, threads_count, filename_2);
            calc_efficiency(calc_speedup(seq_result_2.time, par_result_2.time));

        }
    }

}
