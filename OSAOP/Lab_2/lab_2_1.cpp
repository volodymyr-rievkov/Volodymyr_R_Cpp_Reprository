#include<iostream>
#include<fstream>
#include<sstream>
#include<chrono>
#include<windows.h>
#include<vector>

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

void calculate_average(int thread_id, matrix& m, matrix& result, int start_r, int end_r) 
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
            result[i][j] = sum / count;
        }
    }auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Thread " << thread_id << " is finished in " << duration.count() << "s.\n";
}

void calculate_average_even(int thread_id, matrix& m, matrix& result) 
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
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Thread " << thread_id << " is finished in" << duration.count() << "s.\n";
}

void parallel_matrix_calculation(matrix& m, matrix& result, int threads_n, std::vector<char> thread_priorities) 
{
    bool divide_tasks_due_to_even = false;
    int rows_n = m.size();
    int rows_per_t = rows_n / threads_n;
    HANDLE* threads = new HANDLE[threads_n];
    auto* params = new std::tuple<int, matrix*, matrix*, int, int, bool>[threads_n];
    for (int i = 0; i < threads_n; i++) 
    {
        int start_r = i * rows_per_t;
        int end_row = (i == threads_n - 1) ? rows_n : start_r + rows_per_t;
        params[i] = std::make_tuple(i + 1, &m, &result, start_r, end_row, divide_tasks_due_to_even);
        threads[i] = CreateThread
        (
            NULL,
            0,
            [](LPVOID lpParam) -> DWORD 
            {
                auto params = static_cast<std::tuple<int, matrix*, matrix*, int, int, bool>*>(lpParam);
                int thread_id = std::get<0>(*params);
                matrix& m = *std::get<1>(*params);
                matrix& result = *std::get<2>(*params);
                int start_r = std::get<3>(*params);
                int end_r = std::get<4>(*params);
                bool divide_tasks_due_to_even = std::get<5>(*params);
                if(!divide_tasks_due_to_even)
                {
                    calculate_average(thread_id, m, result, start_r, end_r);
                }
                else
                {
                    calculate_average_even(thread_id, m, result);
                }
                return 0;
            },
            &params[i],
            0,
            NULL
        );
        if(thread_priorities.size() > 0)
        {
            if (threads[i]) 
            {
                switch (thread_priorities[i]) {
                    case 'L':
                        SetThreadPriority(threads[i], THREAD_PRIORITY_LOWEST);
                        break;
                    case 'N':
                        SetThreadPriority(threads[i], THREAD_PRIORITY_NORMAL);
                        break;
                    case 'H':
                        SetThreadPriority(threads[i], THREAD_PRIORITY_HIGHEST);
                        break;
                    default:
                        SetThreadPriority(threads[i], THREAD_PRIORITY_NORMAL);
                }
            }
        }
    }
    WaitForMultipleObjects(threads_n, threads, TRUE, INFINITE);
    for (int i = 0; i < threads_n; ++i) 
    {
        CloseHandle(threads[i]);
    }
    delete[] threads;
    delete[] params;
}

int main()
{
    const std::string m_file = "matrix.txt";
    const std::string r_file = "result.txt";
    const int rows = 100;
    const int cols = 100;
    generate_matrix_into_file(m_file, rows, cols);
    matrix m = read_matrix_from_file(m_file);
    matrix result(rows, std::vector<int>(cols, 0));
    const int threads_n = 2; 
    std::vector<char> thread_priorities = {'L', 'H'};
    auto start_time = std::chrono::high_resolution_clock::now();
    parallel_matrix_calculation(m, result, threads_n, thread_priorities);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    write_matrix_to_file(result, r_file);
    print_info(threads_n, duration.count());
}
