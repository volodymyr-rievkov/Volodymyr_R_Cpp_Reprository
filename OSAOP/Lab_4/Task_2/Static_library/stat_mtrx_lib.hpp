#ifndef STAT_MTRX_LIB_H
#define STAT_MTRX_LIB_H

#include <windows.h>
#include <vector>
#include <string>

using matrix = std::vector<std::vector<int>>;

void generate_matrix_into_file(const std::string& filename, int rows, int cols);
matrix read_matrix_from_file(const std::string& filename);
void write_matrix_to_file(const matrix& m, const std::string& filename);

void print_info(int thread_n, double time);

static DWORD WINAPI monitor_process(LPVOID lpParam);
static DWORD WINAPI monitor_thread(LPVOID lpParam);
static DWORD WINAPI matrix_calculation_task(LPVOID lpParam);

static void set_priority(HANDLE thread, char thread_prior);
static void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, LONG& process_progress, int max_concurrent_threads);

static void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, LONG& p_progress, LONG& t_progress);
static void calculate_average_even(int thread_id, matrix& m, matrix& result, LONG& p_progress, LONG& t_progress);
void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads);

#endif 