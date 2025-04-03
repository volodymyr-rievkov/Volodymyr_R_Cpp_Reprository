#include<iostream>
#include<cmath>
#include<vector>
#include<mpi.h>
using namespace std;

int world_size, world_rank;

struct Result
{
    double result = 0.0;
    double time = 0.0;
};

double func(double x, double a, double z)
{
    double denom = a - 2 * x;
    if (fabs(denom) < 1e-10) return 0.0; 
    return (cos(x) / denom) + (16 * x * cos(x * z) - 2);
}

Result seq_calc(double x_start, double x_end, double a, double z, double h)
{
    double start_time = MPI_Wtime();
    Result result;

    for(double x = x_start; x <= x_end; x += h)
    {
        result.result += func(x, a, z);
    }

    double end_time = MPI_Wtime();
    result.time = end_time - start_time;
    cout << "Result: " << result.result << endl;
    cout << "\033[33mTotal time: " << result.time << "s.\033[0m" << endl;
    return result;
}

Result paral_calc(double x_start, double x_end, double a, double z, double h)
{
    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();
    Result result;
    result.result = 0.0;
    
    double range = (x_end - x_start);
    int total_steps = ceil(range / h);
    int p_steps = total_steps / world_size;
    int extra_steps = total_steps % world_size;

    int local_start = p_steps * world_rank + min(world_rank, extra_steps);
    int local_end = local_start + p_steps - 1 + (world_rank < extra_steps ? 1 : 0);

    for(int i = local_start; i <= local_end; i++)
    {
        double x = x_start + i * h;
        if (x > x_end) break;
        result.result += func(x, a, z);
    }

    double end_time = MPI_Wtime();
    result.time = end_time - start_time;

    double global_result = 0.0;
    double global_time = 0.0;
    MPI_Reduce(&result.result, &global_result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&result.time, &global_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (world_rank == 0) 
    {
        result.result = global_result;
        result.time = global_time;
        cout << "Result: " << result.result << endl;
        cout << "\033[33mTotal time: " << result.time << "s.\033[0m" << endl;
    }

    return result;
}

double calc_speedup(double T_s, double T_p)
{
    double speedup = T_s / T_p;
    cout << "\033[34mParallel speedup: " << speedup << "\033[0m" << endl;
    return speedup;
}

double calc_efficiency(double speedup)
{
    double efficiency = min(speedup / world_size, 1.0);
    cout << "\033[32mParallel efficiency: " << efficiency << "\033[0m" << endl;
    return efficiency;
}

int main(int argc, char** argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const double N = 13;
    const vector<double> Ns = {N, N * 1e2, N * 1e4, N * 1e6};

    for (const double n : Ns)
    {
        double a = N;
        double b = N * 2;
        double z = pow(N, 2);
        double k = N / 2;
        double h = N / k;
        double x_start = 1.0;
        double x_end = N + 1.0;
        
        Result seq_result;
        if (world_rank == 0)
        {
            cout << endl << "N: " << n << endl;
            cout << "----- Sequential function calculation -----" << endl;
            seq_result = seq_calc(x_start, x_end, a, z, h);
            cout << "----- Parallel function calculation -----" << endl;
        }
        
        Result paral_result = paral_calc(x_start, x_end, a, z, h);
        
        if (world_rank == 0)
        {
            calc_efficiency(calc_speedup(seq_result.time, paral_result.time));
        }
    }
    
    MPI_Finalize();
}
