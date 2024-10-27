#include <iostream>
#include <windows.h>

typedef void (*run_calculation_func)(int, int, int, int);

int main() 
{
    HINSTANCE hinstLib = LoadLibrary(TEXT("D:\\Programming\\C,C++Applications\\OSAOP\\Lab_4\\Windows\\Task_1\\Dynaimc_library\\dyn_mtrx_lib.dll"));
    if (hinstLib != NULL) 
    {
        run_calculation_func run_calculation = (run_calculation_func)GetProcAddress(hinstLib, "run_c");
        if(run_calculation)
        {
            run_calculation(1000, 1000, 10, 2);
        }
        else
        {
            MessageBoxW(NULL, L"Func was not loaded.", L"Error", MB_OK | MB_ICONERROR);
        }
        FreeLibrary(hinstLib);
    }
    else 
    {
        MessageBoxW(NULL, L"Library was not loaded.", L"Error", MB_OK | MB_ICONERROR);
    }
} 