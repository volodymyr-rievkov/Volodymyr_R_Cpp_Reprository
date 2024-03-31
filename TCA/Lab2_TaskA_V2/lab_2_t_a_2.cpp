#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

double get_max_length(const vector<long long int>& lengths, int n) 
{
    double left_element = 0;
    double right_element = *max_element(lengths.begin(), lengths.end()) / static_cast<double>(n);
    while (abs(right_element - left_element) > 1e-4) 
    {
        double middle_element = (left_element + right_element) / 2;
        int amount = 0;
        for (auto length : lengths) {
            amount += length / middle_element;
        }
        if (amount >= n) {
            left_element = middle_element;
        } else {
            right_element = middle_element;
        }
    }
    return left_element;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    if(n < 1 || n > 1000 || m < 1 || m > 1000)
    {
        return 0;
    }
    vector<long long int> lengths(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> lengths[i];
        if(lengths[i] < 1 || lengths[i] > 1e9)
        {
            return 0;
        }
    }
    cout << set_precision(7) << get_max_length(lengths, n);
}