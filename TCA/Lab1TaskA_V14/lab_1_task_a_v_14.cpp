#include<iostream>
using namespace std;

int main()
{
    int N;
    int K;
    cin >> N >> K;
    if(N < 1 || N > 10)
    {
        return 0;
    }
    if(K < 0 || K > 10)
    {
        return 0;
    }
    vector<vector<int>> floor(N, vector<int> (N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> floor[i][j];
        }
    }
    int max_side = 0;
    
}