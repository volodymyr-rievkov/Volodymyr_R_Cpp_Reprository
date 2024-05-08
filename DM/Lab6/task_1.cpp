#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void fill_sets(const vector<int> &defined_set, vector<vector<int>> &sets)
{
    int amount = 0;
    int d_set_size = defined_set.size();
    vector<int> buffer_set(d_set_size, 0);
    do
    {
        cout << "Enter amount of arrays: ";
        cin >> amount;
        if(amount < 1)
        {
            cout << "Error: Amount shouldn't be below one." << endl;
        }
    }while (amount < 1);
    cout << "Defined set: { ";
    for(int  element : defined_set)
    {
        cout << element << " ";
    }
    cout << "}" << endl;
    for(int i = 0; i < amount; i++)
    {
        cout << "Enter " << i + 1 << " set:" << endl;
        for(int y = 0; y < d_set_size; y++)
        {
            cin >> buffer_set[y];
            if(!count(defined_set.begin(), defined_set.end(), buffer_set[y]))
            {
                cout << "Error: There is not such number '" << buffer_set[y] << "' in defined set." << endl;   
                y = 0;       
            }
        }
        sets.push_back(buffer_set); 
    }
    sets.shrink_to_fit();
}

void print_sets(const vector<vector<int>> &sets)
{
    int set_size = sets.size();
    for(int i = 0; i < set_size; i++)
    {
        cout << "{ ";
        for(int element : sets[i])
        {
            cout << element << " "; 
        }
        cout << "}" << endl;
    }
}

bool compare_sets(const vector<int>& first_set, const vector<int>& second_set) 
{
    int size = first_set.size();
    for(int i = 0; i < size; ++i) 
    {
        if(first_set[i] != second_set[i]) 
        {
            return first_set[i] < second_set[i];
        }
    }
    return false;
}

int main()
{
    const vector<int> defined_set {1, 2, 3, 4, 5, 6};
    vector<vector<int>> sets;
    fill_sets(defined_set, sets);
    cout << "Sets: ";
    print_sets(sets);
    sort(sets.begin(), sets.end(), compare_sets);
    cout << "Sorted sets:";
    print_sets(sets);
}

//2 3 4 5 6 1
//2 3 1 4 5 6
//1 6 5 4 3 2
//1 5 6 4 2 3
//5 4 3 2 1 6
//5 4 1 2 3 6
//2 3 1 4 6 5
//3 1 4 5 6 2
//4 3 2 5 6 1
//6 5 4 3 2 1
//6 5 4 3 1 2
//4 3 5 6 1 2