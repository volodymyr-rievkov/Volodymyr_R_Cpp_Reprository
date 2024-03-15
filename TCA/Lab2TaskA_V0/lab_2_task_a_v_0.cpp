#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int main()
{
    int N = 0;
    int M = 0;
    cin >> N >> M;
    if(N < 1 || M < 1 || N > 100 || M > 100)
    {
        return 0;
    }
    vector<int> lengths(M, 0);
    for(int i = 0; i < M; i++)
    {
        cin >> lengths[i];
        if(lengths[i] < 1 || lengths[i] > 100)
        {
            return 0;
        }
    }
    double max_length = max_element(lengths.begin(), lengths.end()) / N;
    
}