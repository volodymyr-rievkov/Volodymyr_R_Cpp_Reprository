#ifndef DYN_MTRX_LIB_L_H
#define DYN_MTRX_LIB_L_H

#include <vector>
#include <string>
#include <pthread.h>
#include <atomic>

using matrix = std::vector<std::vector<int>>;

void show_message(const char* message);
extern "C" __attribute__((visibility("default"))) void print_info(int thread_n, double time);

extern "C" __attribute__((visibility("default"))) void generate_matrix_into_file(const std::string& file_name, int rows, int cols);
extern "C" __attribute__((visibility("default"))) matrix read_matrix_from_file(const std::string& file_name);
extern "C" __attribute__((visibility("default"))) void write_matrix_to_file(const matrix& m, const std::string& file_name);

__attribute__((visibility("hidden"))) void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, std::atomic<int>& p_progress, std::atomic<int>& t_progress);
__attribute__((visibility("hidden")))  void calculate_average_even(int thread_id, matrix& m, matrix& result, std::atomic<int>& p_progress, std::atomic<int>& t_progress);

__attribute__((visibility("hidden")))  void set_priority(pthread_t& thread, char thread_prior);
__attribute__((visibility("hidden")))  void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, std::atomic<int>& process_progress, int max_concurrent_threads);

__attribute__((visibility("hidden")))  void* monitor_process(void* args);
__attribute__((visibility("hidden")))  void* monitor_thread(void* args);
__attribute__((visibility("hidden")))  void* matrix_calculation_task(void* args);

extern "C" __attribute__((visibility("default"))) void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads);

extern "C" __attribute__((visibility("default"))) void run_calculation(int rows, int cols, int threads_n, int max_concurrent_threads)__asm__("run_c");

#endif 