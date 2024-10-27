#ifdef __WIN32__
    #include "D:\Programming\C,C++Applications\OSAOP\Lab_4\Windows\Task_2\Static_library\stat_mtrx_lib.hpp"
#elif __linux__
    #include "\home\volodymyr\Projects\Lab_4\Task_2\Static_library\stat_mtrx_lib_l.hpp"
#endif

#include<vector>
#include<chrono>

int main()
{
    const std::string m_file = "matrix.txt";
    const std::string r_file = "result.txt";

    const int rows = 1000;
    const int cols = 1000;

    const int threads_n = 10;
    const int max_concurrent_threads = 2;
    std::vector<char> threads_priorities = {};

    generate_matrix_into_file(m_file, rows, cols);
    matrix m = read_matrix_from_file(m_file);
    matrix result(rows, std::vector<int>(cols, 0));
 
    auto start_time = std::chrono::high_resolution_clock::now();
    parallel_matrix_calculation(m, result, threads_n, threads_priorities, max_concurrent_threads);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    print_info(threads_n, duration.count());

    write_matrix_to_file(result, r_file);
}