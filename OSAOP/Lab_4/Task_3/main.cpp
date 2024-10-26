#include <iostream>
#include <windows.h>
#include <chrono>
#include <vector>

using matrix = std::vector<std::vector<int>>;

typedef void (*generate_matrix_into_file_func)(const std::string&, int, int);
typedef matrix (*read_matrix_from_file_func)(const std::string&);
typedef void (*write_matrix_to_file_func)(matrix&, const std::string&);
typedef void (*parallel_matrix_calculation_func)(matrix&, matrix&, int, std::vector<char>, int);
typedef void (*print_info_func)(int, double);

int main() {
    HINSTANCE hinstLib;
    generate_matrix_into_file_func generate_matrix_into_file;
    read_matrix_from_file_func read_matrix_from_file;
    write_matrix_to_file_func write_matrix_to_file;
    parallel_matrix_calculation_func parallel_matrix_calculation;
    print_info_func print_info;

    hinstLib = LoadLibrary(TEXT("D:\\Programming\\C,C++Applications\\OSAOP\\Lab_4\\Task_1\\Dynaimc_library\\dyn_mtrx_lib.dll"));
    if (hinstLib != NULL) 
    {
        generate_matrix_into_file = (generate_matrix_into_file_func)GetProcAddress(hinstLib, "generate_matrix_into_file");
        read_matrix_from_file = (read_matrix_from_file_func)GetProcAddress(hinstLib, "read_matrix_from_file");
        write_matrix_to_file = (write_matrix_to_file_func)GetProcAddress(hinstLib, "write_matrix_to_file");
        parallel_matrix_calculation = (parallel_matrix_calculation_func)GetProcAddress(hinstLib, "parallel_matrix_calculation");
        print_info = (print_info_func)GetProcAddress(hinstLib, "print_info");

        if (generate_matrix_into_file && read_matrix_from_file && write_matrix_to_file && parallel_matrix_calculation && print_info) 
        {
            const std::string m_file = "D:\\Programming\\C,C++Applications\\OSAOP\\Lab_4\\matrix.txt";
            const std::string r_file = "D:\\Programming\\C,C++Applications\\OSAOP\\Lab_4\\result.txt";

            const int rows = 1000;
            const int cols = 1000;

            const int threads_n = 10;
            const int max_concurrent_threads = 2;
            std::vector<char> threads_priorities = {'L', 'H', 'N'};

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
        else
        {
            MessageBoxW(NULL, L"Funcs were not loaded.", L"Error", MB_OK | MB_ICONERROR);
        }
        FreeLibrary(hinstLib);
    } 
    else 
    {
        MessageBoxW(NULL, L"Library was not loaded.", L"Error", MB_OK | MB_ICONERROR);
    }
}
