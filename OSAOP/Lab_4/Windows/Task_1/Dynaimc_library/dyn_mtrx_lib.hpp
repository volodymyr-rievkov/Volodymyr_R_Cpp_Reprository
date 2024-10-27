#ifndef DYN_MTRX_LIB_H
#define DYN_MTRX_LIB_H

#include <windows.h>
#include <vector>
#include <string>

using matrix = std::vector<std::vector<int>>;

extern"C" __declspec(dllexport) void generate_matrix_into_file(const std::string& filename, int rows, int cols);
extern"C" __declspec(dllexport) matrix read_matrix_from_file(const std::string& filename);
extern"C" __declspec(dllexport) void write_matrix_to_file(const matrix& m, const std::string& filename);

extern"C" __declspec(dllexport) void print_info(int thread_n, double time);

DWORD WINAPI monitor_process(LPVOID lpParam);
DWORD WINAPI monitor_thread(LPVOID lpParam);
DWORD WINAPI matrix_calculation_task(LPVOID lpParam);

void set_priority(HANDLE thread, char thread_prior);
void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, LONG& process_progress, int max_concurrent_threads);

void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, LONG& p_progress, LONG& t_progress);
void calculate_average_even(int thread_id, matrix& m, matrix& result, LONG& p_progress, LONG& t_progress);
extern"C" __declspec(dllexport) void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads);

extern"C" __declspec(dllexport) void CALLBACK run_library(HWND hwnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow);

extern"C" __declspec(dllexport) void run_calculation(int rows, int cols, int threads_n, int max_concurrent_threads)__asm__("run_c");

#endif 
