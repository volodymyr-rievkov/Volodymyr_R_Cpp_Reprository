#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> lucky_nums;

void generate_lucky_nums(int number)
{
    lucky_nums.clear();

    int lucky_four = 4;
    int lucky_seven = 7;

    bool lucky_four_over = false;
    bool lucky_seven_over = false;

    while(!lucky_four_over && !lucky_seven_over)
    {
        if((lucky_four <= number) && !lucky_four_over)
        {
            lucky_nums.push_back(lucky_four);
            lucky_four = lucky_four * 10 + 4;
        }
        else
        {
            lucky_four_over = true;
        }
        if((lucky_seven <= number) && !lucky_seven_over)
        {
            lucky_nums.push_back(lucky_seven);
            lucky_seven = lucky_seven * 10 + 7;
        }
        else
        {
            lucky_seven_over = true;
        }  
    }
    lucky_nums.shrink_to_fit();
}

bool check_sum(int number)
{
    if(lucky_nums.size() == 0)
    {
        return false;
    }
    for(int i = 0; i < lucky_nums.size(); i++)
    {
        for(int y = 0; y < lucky_nums.size(); y++)
        {
            if(number == lucky_nums[i] + lucky_nums[y])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int q = 0;
    cin >> q;
    if(q < 1 || q > 100)
    {
        return 0;
    }
    vector<int> x(q, 0);
    for(int i = 0; i < q; i++)
    {
        cin >> x[i];
        if(x[i] < 1 || x[i] > pow(10, 9))
        {
            return 0;
        }
    }
    for(int i = 0; i < q; i++)
    {
        generate_lucky_nums(x[i]);
        if(check_sum(x[i]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    } 
}