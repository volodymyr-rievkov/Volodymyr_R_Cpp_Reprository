#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int>& a, vector<int>& b) 
{
    int carry = 0;
    vector<int> result;
    for (int i = 0; i < max(a.size(), b.size()) || carry; ++i) 
    {
        if (i == result.size())
            result.push_back(0);

        if (i < a.size())
            result[i] += a[i];
        if (i < b.size())
            result[i] += b[i];

        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    return result;
}

vector<int> power_of_two(int n) 
{
    vector<int> result;
    result.push_back(1); 
    for (int i = 0; i < n; ++i) 
    {
        result = add(result, result); 
    }
    return result;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> result = power_of_two(n);
    int k;
    cin >> k;
    cout << result[k] << endl;
}