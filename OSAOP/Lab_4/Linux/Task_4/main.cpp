#include <iostream>

#ifdef __linux__
    #include <dlfcn.h>
#endif

typedef void (*run_calculation_func)(int, int, int, int);

int main() 
{
    #ifdef __linux__
        void* handle = dlopen("/home/volodymyr/Projects/Lab_4/Task_2/Static_library/dyn_mtrx_lib_l.so", RTLD_LAZY);
        if(handle != NULL)
        {
            run_calculation_func run_calculation = (run_calculation_func) dlsym(handle, "run_c");
            if(run_calculation)
            {
                run_calculation(1000, 1000, 10, 2);
            }
            else
            {
                std::cerr << "Error: Func was not loaded.";
            }
            dlclose(handle);
        }
        else
        {
            std::cerr << "Error: Library was not loaded.";
        }
    #endif
} 