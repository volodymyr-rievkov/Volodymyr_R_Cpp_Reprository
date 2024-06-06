#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool sort_by_second(const pair<int, int>& first, const pair<int, int>& second)
{
    return first.second < second.second; 
}

int main()
{
    string expression;
    cin >> expression;
    vector<pair<int, int>> gaps_indexes;
    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '(')
        {
            int count = 0;
            for(int y = i + 1; y < expression.size(); y++)
            {
                if(expression[y] == '(')
                {
                    count++;
                }
                if(expression[y] == ')')
                {
                    if(count == 0)
                    {
                        gaps_indexes.push_back({i + 1, y + 1});
                        break;
                    }
                    else
                    {
                        count--;
                    }
                }
            }
        }
    }
    gaps_indexes.shrink_to_fit();
    sort(gaps_indexes.begin(), gaps_indexes.end(), sort_by_second);
    cout << gaps_indexes.size() << endl;
    for(int i = 0; i < gaps_indexes.size(); i++)
    {
        cout << gaps_indexes[i].first << " " << gaps_indexes[i].second << endl;
    }
}