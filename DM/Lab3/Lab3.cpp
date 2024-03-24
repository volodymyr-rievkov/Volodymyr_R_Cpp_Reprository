#include<iostream>
#include<vector>
using namespace std;

void set_vector(vector<int> &vector)
{
    int size = 0;
    int element = 0;
    cout << "Enter size: ";
    cin >> size;
    for(int i = 0; i < size; i++)
    {
        cout << ": ";
        cin >> element;
        vector.push_back(element);
    }
    vector.shrink_to_fit();
}

bool condition(int a, int b)
{
    return (5*a - b) > 3;
}

void set_matrix(vector<vector<int>> &matrix, vector<int> &A, vector<int> &B)
{
    for(int i = 0; i < A.size(); i++)
    {
        for(int y = 0; y < B.size(); y++)
        {
            if(condition(A[i], B[y]))
            {
                matrix[i][y] = 1;
            }
        }
    }
}

void print_matrix(vector<vector<int>> &matrix)
{
    cout << "Matrix: " << endl;
    for(auto row : matrix) 
    {
        cout << "| ";
        for(auto element : row) 
        {
            cout << element << " | ";
        }
        cout << endl;
    }
}

bool is_reflexive(vector<vector<int>>&matrix)
{
    for(int i = 0; i < matrix.size(); i++) 
    {
        if(matrix[i][i] != 1) 
        {
            return false;
        }
    }
    return true;
}

bool is_symmetric(vector<vector<int>> &matrix)
{
    for(int i = 0; i < matrix.size(); i++) 
    {
        for(int y = 0; y < i; y++)
        {
            if(matrix[i][y] != matrix[y][i]) 
            {
                return false;
            }
        }
    }
    return true;
}

bool is_transistive(vector<vector<int>> &matrix)
{
    for(int i = 0; i < matrix.size(); i++) 
    {
        for(int y = 0; y < matrix.size(); y++) 
        {
            for(int j = 0; j < matrix.size(); j++) 
            {
                if (matrix[i][y] && matrix[y][j] && !matrix[i][j]) 
                {
                    return false;
                }
            } 
        }
    }
    return true;
}

int main()
{
    vector<int> A;
    vector<int> B;
    cout << "Enter A elements" << endl;
    set_vector(A);
    cout << "Enter B elements" << endl;
    set_vector(B);
    vector<vector<int>> matrix(A.size(), vector<int>(B.size(), 0));
    set_matrix(matrix, A, B);
    print_matrix(matrix);
    cout << "Reflexive: " << (is_reflexive(matrix) ? "True" : "False") << endl;
    cout << "Symmetric: " << (is_symmetric(matrix) ? "True" : "False") << endl;
    cout << "Transistive: " << (is_transistive(matrix) ? "True" : "False") << endl;
}