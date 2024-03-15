#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void fill_vector(vector<int> &vector)
{
    int vector_size = 0;
    cout << "Enter size: ";
    cin >> vector_size;
    int element = 0;
    for(int i = 0; i < vector_size; i++)
    {
        cout << ": ";
        cin >> element;
        vector.push_back(element);
    }
    vector.shrink_to_fit();
}

void print_power(vector<int> &vector)
{
    cout << "Power: " <<  vector.size() << endl;
    cout << "Bulean Power: " << pow(2, vector.size()) << endl;
}

void print_vector(vector<int> &vector)
{
    int v_size = vector.size();
    cout << "{ ";
    for(int i = 0; i < v_size; i++)
    {
        cout << vector[i];
        if(i != (v_size - 1))
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

vector<int> set_union(vector<int> &vector_1, vector<int> &vector_2)
{
    vector<int> vector;
    for(int i = 0; i < vector_1.size(); i++)
    {
        vector.push_back(vector_1[i]);
    }
    for(int i = 0; i < vector_2.size(); i++)
    {
        if(!count(vector.begin(), vector.end(), vector_2[i]))
        {
            vector.push_back(vector_2[i]);
        }    
    }
    vector.shrink_to_fit();
    return vector;
}

vector<int> set_intersection(vector<int> &vector_1, vector<int> &vector_2)
{
    vector<int> vector;
    for(int i = 0; i < vector_1.size(); i++)
    {
        for(int y = 0; y < vector_2.size(); y++)
        {
            if(vector_1[i] == vector_2[y])
            {
                vector.push_back(vector_1[i]);
                break;
            }
        }
    }
    vector.shrink_to_fit();
    return vector;
}

bool check_absorption_law_1(vector<int> &vector_1, vector<int> &vector_2)
{
    vector<int> vector = set_union(vector_1, vector_2);
    vector = set_intersection(vector, vector_1);
    sort(vector.begin(), vector.end());
    sort(vector_1.begin(), vector_1.end());
    if(vector == vector_1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool check_absorption_law_2(vector<int> &vector_1, vector<int> &vector_2)
{
    vector<int> vector = set_intersection(vector_1, vector_2);
    vector = set_union(vector, vector_1);
    sort(vector.begin(), vector.end());
    sort(vector_1.begin(), vector_1.end());
    if(vector == vector_1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    vector<int> vector_1;
    fill_vector(vector_1);
    print_power(vector_1);
    cout << "First:" << endl;
    print_vector(vector_1);
    vector<int> vector_2;
    fill_vector(vector_2);
    print_power(vector_2);
    cout << "Second:" << endl;
    print_vector(vector_2);
    vector<int> vector = set_union(vector_1, vector_2);
    cout << "Union:" << endl;
    print_vector(vector);
    vector = set_intersection(vector_1, vector_2);
    cout << "Intersection:" << endl;
    print_vector(vector);
    cout << "Absorption law 1: ";
    if(check_absorption_law_1(vector_1, vector_2))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
    cout << "Absorption law 2: ";
    if(check_absorption_law_2(vector_1, vector_2))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
}