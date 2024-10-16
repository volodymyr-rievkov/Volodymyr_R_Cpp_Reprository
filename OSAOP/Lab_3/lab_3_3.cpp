#include<iostream>
#include<fstream>
#include<sstream>
#include<chrono>
#include<vector>
#include<mutex>
#include<semaphore.h>
#include<atomic>
#include<thread>

#ifdef __linux__
#include <gtk/gtk.h>
#elif __WIN32__
#include <windows.h>
#endif

std::mutex mtx;
sem_t semaphore;

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

void generate_matrix_into_file(const std::string& file_name, int rows, int cols)
{
    std::ofstream out_file(file_name);
    if (!out_file)
    {
        #ifdef __WIN32__
        MessageBoxW(NULL, L"Error: File cannot be opened!", L"Error", MB_OK | MB_ICONERROR);
        #elif __linux__
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

matrix read_matrix_from_file(const std::string& file_name)
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
        #ifdef __WIN32__
        MessageBoxW(NULL, L"Error: File cannot be opened!", L"Error", MB_OK | MB_ICONERROR);
        #elif __linux__
        show_message("Error: File cannot be opened!");
        #endif        
    }
    return m;
}

void write_matrix_to_file(const matrix& m, const std::string& file_name)
{
    std::ofstream out_file(file_name);
    if (!out_file)
    {
        #ifdef __WIN32__
        MessageBoxW(NULL, L"Error: File cannot be opened!", L"Error", MB_OK | MB_ICONERROR);
        #elif __linux__
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

void print_info(int thread_n, double time)
{
    #ifdef __linux__
    string message = "Matrix was successfully calculated\n";
    message += "Number of threads: " + std::to_string(thread_n) + "\n";
    message += "Time taken: " + std::to_string(time) + "s";
    show_message(message.c_str());
    #elif __WIN32__
    std::wstring message = L"Matrix was successfully calculated\n";
    message += L"Number of threads: " + std::to_wstring(thread_n) + L"\n";
    message += L"Time taken: " + std::to_wstring(time) + L"s";
    MessageBoxW(NULL, message.c_str(), L"Information", MB_OK | MB_ICONINFORMATION);
    #endif
}

void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, std::atomic<int>& p_progress, std::atomic<int>& t_progress) 
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

void calculate_average_even(int thread_id, matrix& m, matrix& result, std::atomic<int>& p_progress, std::atomic<int>& t_progress) 
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

void set_priority(std::thread& thread, char thread_prior)
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
    pthread_setschedparam(thread.native_handle(), SCHED_FIFO, &sch_params);
}

void monitor_process(int total_threads, std::atomic<int>& progress) 
{
    while (progress < total_threads) 
    {
        double percentage = (static_cast<double>(progress) / total_threads) * 100.0;
        mtx.lock();
        std::cout << "Process progress: " << percentage << "%\n";
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    mtx.lock();
    std::cout << "Process progress: 100.00%\n";
    mtx.unlock();
}

void monitor_thread(int total_elements, int thread_id, std::atomic<int>& progress) 
{
    while (progress < total_elements) 
    {
        double percentage = (static_cast<double>(progress) / total_elements) * 100.0;
        mtx.lock();
        std::cout << "Thread "<< thread_id << " progress: " << percentage << "%\n";
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    mtx.lock();
    std::cout << "Thread " << thread_id << " progress: 100.00%\n";
    mtx.unlock();
}

void matrix_calculation_task(int thread_id, matrix& m, matrix& result, int start_r, int end_r, int elements, bool divide_tasks, std::atomic<int>& p_progress, std::atomic<int>& t_progress) 
{
    std::thread monitor_thread_t(monitor_thread, elements, thread_id, ref(t_progress));
    if (!divide_tasks) 
    {
        calculate_average(thread_id, m, result, start_r, end_r, ref(p_progress), ref(t_progress));
    } 
    else 
    {
        calculate_average_even(thread_id, m, result, ref(p_progress), ref(t_progress));
    }
    monitor_thread_t.join();            
    sem_post(&semaphore); 
}

void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, std::atomic<int>& process_progress, int max_concurrent_threads) 
{
    sem_init(&semaphore, 0, max_concurrent_threads);
    std::vector<std::thread> threads;
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
        threads.emplace_back([&, i]() { 
            matrix_calculation_task(i + 1, m, result, start_row, end_row, elements_n, divide_tasks_due_to_even, ref(process_progress), ref(thread_progress));
        });
        if (thread_priorities.size() > 0) 
        {
            set_priority(threads[i], thread_priorities[i]);
        }
    }
    for (auto& thread : threads) 
    {
        thread.join();
    }
    sem_destroy(&semaphore);
}

void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads) 
{
    std::atomic<int> process_progress = 0;
    bool divide_tasks_due_to_even = false;
    std::thread monitor_process_t(monitor_process, threads_n, ref(process_progress));
    setup_threads(m, result, threads_n, threads_priorities, divide_tasks_due_to_even, ref(process_progress), max_concurrent_threads);
    monitor_process_t.join();
}

int main()
{
    const std::string m_file = "matrix.txt";
    const std::string r_file = "result.txt";

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