#include<iostream>
#include<sstream>
using namespace std;

int get_size()
{
    int size;
    cin >> size;
    return size;
}

void fill_array(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

int get_max_array_number(int* array, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int get_min_array_number(int* array, int size, int max)
{
    int min = max;
    for(int i = 0; i < size; i++)
    {
        if(array[i] < min && array[i] != -1)
        {
            min = array[i];
        }
    }
    return min;
}

int get_count_of_array_number(int* array, int size, int number)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(number == array[i])
        {
            count++;
        }
    }
    return count;
}

void delete_array_number(int* array, int size, int number)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == number)
        {
            array[i] = -1;
        }
    }
}

int get_result(int* array, int size)
{
    int max = get_max_array_number(array, size);
    int min = get_min_array_number(array, size, max);
    int max_count = get_count_of_array_number(array, size, max);
    int min_count = get_count_of_array_number(array, size, min);
    if(max_count == min_count)
    {
        delete_array_number(array, size, max);
    }
    else
    {
        if(max_count < min_count)
        {
            delete_array_number(array, size, max);
        }
        else
        {
            delete_array_number(array, size, min);
        }
    }
    max = get_max_array_number(array, size);
    min = get_min_array_number(array, size, max);
    return  max - min;
}

int main()
{
    int size = get_size();
    if(size < 1)
    {
        return 0;
    }
    int a_road[size];
    fill_array(a_road, size);
    for(int i = 0 ; i < size; i++)
    {
        if(a_road[i] < 0)
        {
            return 0;
        }
    }
    cout << get_result(a_road, size);
}