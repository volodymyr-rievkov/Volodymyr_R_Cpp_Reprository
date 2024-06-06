#include<iostream>
using namespace std;

bool binary_search(int *array, int size, int search_value)
{
    int left = 0;
    int right = size - 1;
    int mid;
    while(left <= right)
    {    
        mid = (left + right) / 2;
        if(search_value == array[mid])
        {
            return true;
        }
        else if(search_value > array[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    const int size = 8;
    int array[size] = {12, 24, 36, 48, 60, 72, 84, 96};
    if(binary_search(array, size, 24))
    {
        cout << "Value was found." << endl;
    }
    else
    {
        cerr << "Error: Value was not found!" << endl;
    }
}