#include<iostream>
#include<algorithm>
using namespace std;

int N;
int result;
int *radius = nullptr;
int *volume = nullptr;

void set_N()
{
    cin >> N;
}

void set_radius()
{
    radius = new int[N];
    for (int i = 0; i < N; ++i) 
    {
        cin >> radius[i];
    }
}

void set_volume()
{
    volume = new int[N];
    for (int i = 0; i < N; ++i) 
    {
        cin >> volume[i];
    }
}

bool N_check()
{
    return (N >= 1) && (N <= 2 * 100000);
}

bool element_check(int element)
{
    return (element >= 1) && (element <= 1000000000);
}

bool arr_check(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(!element_check(array[i]))
        {
            return 0;
        }
    }
    return 1;
}

// bool contain_sim_elements()
// {
//     for(int i = 0; i < N; i++)
//     {
//         for(int y = i + 1; y < N; y++)
//         {
//             if(radius[i] == radius[y])
//             {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

void set_result()
{
    int max_element;
    int element;
    result = 0;
    // if(contain_sim_elements())
    // {
        for(int i = 0; i < N; i++)
        {
            max_element = 0;
            if(radius[i] != 0)
            {
                element = radius[i];
                for(int y = i; y < N; y++)
                {
                    if(element == radius[y])
                    {
                        max_element = max(max_element, volume[y]);
                        radius[y] = 0;
                    }
                }
            }
            result += max_element;
        }
    // }
    // else
    // {
    //     for(int i = 0; i < N; i++)
    //     {
    //         result += volume[i];
    //     }
    // }
}

int main()
{
    set_N();
    if(!N_check())
    {
        return 0;
    }
    set_radius();
    if(!arr_check(radius, N))
    {
        return 0;
    }
    set_volume();
    if(!arr_check(volume, N))
    {
        return 0;
    }
    set_result();
    cout << result;
    delete[] radius;
    delete[] volume;
}