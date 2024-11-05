#ifndef STAT_MTRX_LIB_L_V1_H
#define STAT_MTRX_LIB_L_V1_H

#include <vector>
#include <string>
#include <pthread.h>
#include <atomic>

using matrix = std::vector<std::vector<int>>;

static void show_message(const char* message);
void print_info(int thread_n, double time);

void generate_matrix_into_file(const std::string& file_name, int rows, int cols);
matrix read_matrix_from_file(const std::string& file_name);
void write_matrix_to_file(const matrix& m, const std::string& file_name);

static void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, std::atomic<int>& p_progress, std::atomic<int>& t_progress);
static void calculate_average_even(int thread_id, matrix& m, matrix& result, std::atomic<int>& p_progress, std::atomic<int>& t_progress);

static void set_priority(pthread_t& thread, char thread_prior);
static void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, std::atomic<int>& process_progress, int max_concurrent_threads);

static void* monitor_process(void* args);
static void* monitor_thread(void* args);
static void* matrix_calculation_task(void* args);

void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads);

#endif 