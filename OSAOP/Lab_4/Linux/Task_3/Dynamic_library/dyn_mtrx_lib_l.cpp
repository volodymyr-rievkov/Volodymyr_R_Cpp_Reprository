#include"dyn_mtrx_lib_l.hpp"

#include<iostream>
#include<fstream>
#include<sstream>
#include<chrono>
#include<vector>
#include<mutex>
#include<semaphore.h>
#include<atomic>
#include<pthread.h>
#include<unistd.h>

#ifdef __linux__
#include <gtk/gtk.h>
#endif

__attribute__((visibility("hidden")))  std::mutex mtx;
__attribute__((visibility("hidden")))  sem_t semaphore;

using matrix = std::vector<std::vector<int>>;
 
void show_message(const char* message) 
{   
    #ifdef __linux__ 
    gtk_init(NULL, NULL);
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, 
                                    GTK_MESSAGE_INFO, GTK_BUTTONS_OK, 
                                    "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    #endif
}

extern "C" __attribute__((visibility("default"))) void generate_matrix_into_file(const std::string& file_name, int rows, int cols)
{
    std::ofstream out_file(file_name);
    if (!out_file)
    {
        #ifdef __linux__
        show_message("Error: File cannot be opened!");
        #endif
        return;
    }
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            out_file << rand() % 100 << " ";
        }
        out_file << "\n";
    }
    out_file.close();
}

extern "C" __attribute__((visibility("default"))) matrix read_matrix_from_file(const std::string& file_name)
{
    std::ifstream file(file_name);
    matrix m;
    std::string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::vector<int> row;
            std::stringstream ss(line);
            int value;
            while (ss >> value) {
                row.push_back(value);
            }
            m.push_back(row);
        }
        file.close();
    }
    else
    {
        #ifdef __linux__
        show_message("Error: File cannot be opened!");
        #endif        
    }
    return m;
}

extern "C" __attribute__((visibility("default"))) void write_matrix_to_file(const matrix& m, const std::string& file_name)
{
    std::ofstream out_file(file_name);
    if (!out_file)
    {
        #ifdef __linux__
        show_message("Error: File cannot be opened!");
        #endif
        return;
    }
    for (const auto& row : m)
    {
        for (const auto& val : row)
        {
            out_file << val << " ";
        }
        out_file << "\n";
    }
    out_file.close();
}

extern "C" __attribute__((visibility("default"))) void print_info(int thread_n, double time)
{
    #ifdef __linux__
    std::string message = "Matrix was successfully calculated\n";
    message += "Number of threads: " + std::to_string(thread_n) + "\n";
    message += "Time taken: " + std::to_string(time) + "s";
    show_message(message.c_str());
    #endif
}

__attribute__((visibility("hidden")))  void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, std::atomic<int>& p_progress, std::atomic<int>& t_progress) 
{
    int rows = m.size();
    int cols = m[0].size();
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = start_r; i < end_r; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            double sum = 0;
            int count = 0;
            for (int di = -1; di <= 1; ++di) 
            {
                for (int dj = -1; dj <= 1; ++dj) 
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) 
                    {
                        sum += m[ni][nj];
                        count++;
                    }
                }
            }
            result[i][j] = (count > 0) ? sum / count : 0;
            t_progress.fetch_add(1);
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    mtx.lock();
    std::cout << "Thread " << thread_id << " is finished in " << duration.count() << "s.\n";
    mtx.unlock();
    p_progress.fetch_add(1);
}

__attribute__((visibility("hidden")))  void calculate_average_even(int thread_id, matrix& m, matrix& result, std::atomic<int>& p_progress, std::atomic<int>& t_progress) 
{
    int rows = m.size();
    int cols = m[0].size();
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            double sum = 0;
            int count = 0;
            for (int di = -1; di <= 1; ++di) 
            {
                for (int dj = -1; dj <= 1; ++dj) 
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) 
                    {
                        if ((thread_id == 1 && m[ni][nj] % 2 == 0) || (thread_id == 2 && m[ni][nj] % 2 != 0)) 
                        {
                            sum += m[ni][nj];
                            count++;
                        }
                    }
                }
            }
            result[i][j] = (count > 0) ? sum / count : 0;
            t_progress.fetch_add(1);
        }
        
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    mtx.lock();
    std::cout << "Thread " << thread_id << " is finished in" << duration.count() << "s.\n";
    mtx.unlock();
    p_progress.fetch_add(1);
}

__attribute__((visibility("hidden")))  void set_priority(pthread_t& thread, char thread_prior)
{
    sched_param sch_params;
    switch (thread_prior) 
    {
        case 'L':
            sch_params.sched_priority = 10;
            break;
        case 'N':
               sch_params.sched_priority = 20;
               break;
        case 'H':
            sch_params.sched_priority = 30;
            break;
        default:
             sch_params.sched_priority = 20;
    }
    pthread_setschedparam(thread, SCHED_FIFO, &sch_params);
}

__attribute__((visibility("hidden")))  void* monitor_process(void* args) 
{
    auto* data = static_cast<std::tuple<int, int, std::atomic<int>*>*>(args);
    int total_threads = std::get<0>(*data);
    int thread_id = std::get<1>(*data);
    std::atomic<int>& progress = *std::get<2>(*data);
    while (progress < total_threads) 
    {
        double percentage = (static_cast<double>(progress) / total_threads) * 100.0;
        mtx.lock();
        std::cout << "Process progress: " << percentage << "%\n";
        mtx.unlock();
        sleep(1);
    }
    mtx.lock();
    std::cout << "Process progress: 100.00%\n";
    mtx.unlock();
    return nullptr;
}

__attribute__((visibility("hidden")))  void* monitor_thread(void* args) 
{
    auto* data = static_cast<std::tuple<int, int, std::atomic<int>*>*>(args);
    int total_elements = std::get<0>(*data);
    int thread_id = std::get<1>(*data);
    std::atomic<int>& progress = *std::get<2>(*data);

    while (progress < total_elements) 
    {
        double percentage = (static_cast<double>(progress) / total_elements) * 100.0;
        mtx.lock();
        std::cout << "Thread "<< thread_id << " progress: " << percentage << "%\n";
        mtx.unlock();
        sleep(1);
    }
    mtx.lock();
    std::cout << "Thread " << thread_id << " progress: 100.00%\n";
    mtx.unlock();
    return nullptr;
}

__attribute__((visibility("hidden")))  void* matrix_calculation_task(void* args) 
{
    auto* data = static_cast<std::tuple<int, int, int, matrix*, matrix*, bool, std::atomic<int>*, std::atomic<int>*, int>*>(args);
    int thread_id = std::get<0>(*data);
    int start_r = std::get<1>(*data);
    int end_r = std::get<2>(*data);
    matrix& m = *std::get<3>(*data);
    matrix& result = *std::get<4>(*data);
    bool divide_tasks = std::get<5>(*data);
    std::atomic<int>& p_progress = *std::get<6>(*data);
    std::atomic<int>& t_progress = *std::get<7>(*data);
    int elements = std::get<8>(*data);
    pthread_t monitor_thread_t;
    auto* params = new std::tuple(elements, thread_id, ref(t_progress));
    pthread_create(&monitor_thread_t, nullptr, monitor_thread, params);
    if (!divide_tasks) 
    {
        calculate_average(thread_id, m, result, start_r, end_r, ref(p_progress), ref(t_progress));
    } 
    else 
    {
        calculate_average_even(thread_id, m, result, ref(p_progress), ref(t_progress));
    }
    pthread_join(monitor_thread_t, nullptr);
    delete params;
    sem_post(&semaphore); 
    return nullptr;
}

__attribute__((visibility("hidden")))  void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, std::atomic<int>& process_progress, int max_concurrent_threads) 
{
    sem_init(&semaphore, 0, max_concurrent_threads);
    std::vector<pthread_t> threads;
    std::atomic<int> thread_progress = 0;
    int rows_n = m.size();
    int cols_n = m[0].size();
    for (int i = 0; i < threads_n; i++) 
    {
        sem_wait(&semaphore); 
        int rows_per_t = rows_n / threads_n;
        int start_row = i * rows_per_t;
        int end_row = (i == threads_n - 1) ? rows_n : start_row + rows_per_t;
        int elements_n = rows_per_t * cols_n;
        thread_progress = 0;
        auto* params = new std::tuple(i + 1, start_row, end_row, &m, &result, divide_tasks_due_to_even, ref(process_progress), ref(thread_progress), elements_n);
        pthread_t thread;
        pthread_create(&thread, nullptr, matrix_calculation_task, params);
        threads.push_back(thread);
        if (thread_priorities.size() > 0) 
        {
            set_priority(threads[i], thread_priorities[i]);
        }
    }
    for (auto& thread : threads) 
    {
        pthread_join(thread, NULL);
    }
    sem_destroy(&semaphore);
}

extern "C" __attribute__((visibility("default"))) void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads) 
{
    std::atomic<int> process_progress = 0;
    bool divide_tasks_due_to_even = false;
    auto* params = new std::tuple(threads_n, ref(process_progress));
    pthread_t monitor_process_t;
    pthread_create(&monitor_process_t, nullptr, monitor_process, params);
    setup_threads(m, result, threads_n, threads_priorities, divide_tasks_due_to_even, ref(process_progress), max_concurrent_threads);
    pthread_join(monitor_process_t, NULL);
    delete params; 
}

extern "C" __attribute__((visibility("default"))) void run_calculation(int rows, int cols, int threads_n, int max_concurrent_threads)
{
    const std::string m_file = "matrix.txt";
    const std::string r_file = "result.txt";

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
