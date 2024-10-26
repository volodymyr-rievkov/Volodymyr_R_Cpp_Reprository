#include"stat_mtrx_lib.hpp"

#include<iostream>
#include<fstream>
#include<sstream>
#include<chrono>
#include<windows.h>
#include<vector>

HANDLE semaphore;
CRITICAL_SECTION cs;

using matrix = std::vector<std::vector<int>>;

void generate_matrix_into_file(const std::string& file_name, int rows, int cols)
{
    std::ofstream out_file(file_name);
    if(!out_file)
    {
        MessageBoxW(NULL, L"Error: File cannot be opened!", L"Error", MB_OK | MB_ICONERROR);
        return;
    }
    srand(time(0)); 
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
        MessageBoxW(NULL, L"Error: File cannot be opened!", L"Error", MB_OK | MB_ICONERROR);
    }
    return m;
}

void write_matrix_to_file(const matrix& m, const std::string& file_name) 
{
    std::ofstream out_file(file_name);
    if (!out_file) 
    {
        MessageBoxW(NULL, L"Error: File cannot be opened!", L"Error", MB_OK | MB_ICONERROR);
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
    std::wstring message = L"Matrix was successfully calculated\n";
    message += L"Number of threads: " + std::to_wstring(thread_n) + L"\n";
    message += L"Time taken: " + std::to_wstring(time) + L"s";
    MessageBoxW(NULL, message.c_str(), L"Information", MB_OK | MB_ICONINFORMATION);
}

static void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r, LONG& p_progress, LONG& t_progress) 
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
            InterlockedIncrement(&t_progress);
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    EnterCriticalSection(&cs);
    std::cout << "Thread " << thread_id << " is finished in " << duration.count() << "s.\n";
    LeaveCriticalSection(&cs);
    InterlockedIncrement(&p_progress);
}

static void calculate_average_even(int thread_id, matrix& m, matrix& result, LONG& p_progress, LONG& t_progress) 
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
            InterlockedIncrement(&t_progress);
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    EnterCriticalSection(&cs);
    std::cout << "Thread " << thread_id << " is finished in" << duration.count() << "s.\n";
    LeaveCriticalSection(&cs);
    InterlockedIncrement(&p_progress);
}

static void set_priority(HANDLE thread, char thread_prior)
{
    if (thread) 
    {
        switch (thread_prior) 
        {
            case 'L':
                SetThreadPriority(thread, THREAD_PRIORITY_LOWEST);
                break;
            case 'N':
                SetThreadPriority(thread, THREAD_PRIORITY_NORMAL);
                break;
            case 'H':
                SetThreadPriority(thread, THREAD_PRIORITY_HIGHEST);
                break;
            default:
                SetThreadPriority(thread, THREAD_PRIORITY_NORMAL);
        }
    }
}

static DWORD WINAPI monitor_process(LPVOID lpParam) 
{
    auto params = static_cast<std::tuple<int, LONG*>*>(lpParam);
    int total_threads = std::get<0>(*params);
    LONG& progress = *std::get<1>(*params);
    while (progress < total_threads) 
    {
        double percentage = (static_cast<double>(progress) / total_threads) * 100.0;
        EnterCriticalSection(&cs);
        std::cout << "Process progress: " << percentage << "%\n";
        LeaveCriticalSection(&cs);
        Sleep(1000);
    }
    EnterCriticalSection(&cs);
    std::cout << "Process progress: 100.00%\n";
    LeaveCriticalSection(&cs);
    return 0;
}

static DWORD WINAPI monitor_thread(LPVOID lpParam) 
{
    auto params = static_cast<std::tuple<int, int, LONG*>*>(lpParam);
    int total_elements = std::get<0>(*params);
    int thread_id = std::get<1>(*params);
    LONG& progress = *std::get<2>(*params);
    while (progress < total_elements) 
    {
        double percentage = (static_cast<double>(progress) / total_elements) * 100.0;
        EnterCriticalSection(&cs);
        std::cout << "Thread "<< thread_id << " progress: " << percentage << "%\n";
        LeaveCriticalSection(&cs);
        Sleep(1000);
    }
    EnterCriticalSection(&cs);
    std::cout << "Thread " << thread_id << " progress: 100.00%\n";
    LeaveCriticalSection(&cs);
    return 0;
}

static DWORD WINAPI matrix_calculation_task(LPVOID lpParam) 
{
    auto params = static_cast<std::tuple<int, matrix*, matrix*, int, int, bool, LONG*, LONG*, int>*>(lpParam);
    int thread_id = std::get<0>(*params);
    matrix& m = *std::get<1>(*params);
    matrix& result = *std::get<2>(*params);
    int start_r = std::get<3>(*params);
    int end_r = std::get<4>(*params);
    bool divide_tasks = std::get<5>(*params);
    LONG* p_progress = std::get<6>(*params);
    LONG* t_progress = std::get<7>(*params);
    int elements = std::get<8>(*params);
    auto* inside_params = new std::tuple<int, int, LONG*>(elements, thread_id, t_progress);
    HANDLE monitor_thread_t = CreateThread(NULL, 0, monitor_thread, inside_params, 0, NULL);
    if (!divide_tasks) 
    {
        calculate_average(thread_id, m, result, start_r, end_r, *p_progress, *t_progress);
    } 
    else 
    {
        calculate_average_even(thread_id, m, result, *p_progress, *t_progress);
    }
    WaitForSingleObject(monitor_thread_t, INFINITE);
    CloseHandle(monitor_thread_t);
    delete[] inside_params;
    ReleaseSemaphore(semaphore, 1, NULL);
    return 0;
}

static void setup_threads(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities, bool divide_tasks_due_to_even, LONG& process_progress, int max_concurrent_threads) 
{
    semaphore = CreateSemaphore(NULL, max_concurrent_threads, max_concurrent_threads, NULL);
    InitializeCriticalSection(&cs);
    HANDLE* threads = new HANDLE[threads_n];
    auto* params = new std::tuple<int, matrix*, matrix*, int, int, bool, LONG*, LONG*, int>[threads_n];
    LONG thread_progress = 0;
    for (int i = 0; i < threads_n; i++) 
    {
        WaitForSingleObject(semaphore, INFINITE);
        int rows_n = m.size();
        int cols_n = m[0].size();
        int rows_per_t = rows_n / threads_n;
        int start_row = i * rows_per_t;
        int end_row = (i == threads_n - 1) ? rows_n : start_row + rows_per_t;
        int elements_n = rows_per_t * cols_n;
        thread_progress = 0;
        params[i] = std::make_tuple(i + 1, &m, &result, start_row, end_row, divide_tasks_due_to_even, &process_progress, &thread_progress, elements_n);
        threads[i] = CreateThread(NULL, 0, matrix_calculation_task, &params[i], 0, NULL);
        if (thread_priorities.size() > 0) 
        {
            set_priority(threads[i], thread_priorities[i]);
        }
    }
    WaitForMultipleObjects(threads_n, threads, TRUE, INFINITE);
    for (int i = 0; i < threads_n; ++i) 
    {
        CloseHandle(threads[i]);
    }
    DeleteCriticalSection(&cs);
    CloseHandle(semaphore);
    delete[] threads;
    delete[] params;
}

void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> threads_priorities, int max_concurrent_threads) 
{
    LONG process_progress = 0;
    bool divide_tasks_due_to_even = false;
    auto* params = new std::tuple<int, LONG*>(threads_n, &process_progress);
    HANDLE monitor_process_t = CreateThread(NULL, 0, monitor_process, params, 0, NULL);
    setup_threads(m, result, threads_n, threads_priorities, divide_tasks_due_to_even, process_progress, max_concurrent_threads);
    WaitForSingleObject(monitor_process_t, INFINITE);
    CloseHandle(monitor_process_t);
    delete[] params;
}
