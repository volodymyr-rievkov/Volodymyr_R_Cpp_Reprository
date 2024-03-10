#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool word_check(string word)
{
    if(word.length() > 20)
    {
        return false;
    }
    for(int i = 0; i < word.length(); i++)
    {
        if(!islower(word[i]) || word[i] < 'a' || word[i] > 'z')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string secret_word;
    cin >> secret_word;
    if(!word_check(secret_word))
    {
        return 0;
    }
    vector<int> count_of_letters(secret_word.length(), 0);
    int number;
    cin >> number;
    if(number < 1 || number > 1000)
    {
        return 0;
    }
    vector<string> banners;
    string banner;
    for(int i = 0; i < number; i++)
    {
        cin >> banner;
        if(!word_check(banner))
        {
            return 0;
        }
        banners.push_back(banner);
    }
    for(int i = 0; i < number; i++)
    {
        for(int y = 0; y < banners[i].length(); y++)
        {
            for(int j = 0; j < secret_word.length(); j++)
            {
                if(banners[i][y] == secret_word[j])
                {
                    count_of_letters[j]++;
                }
            }
        }
    }
    int result = *min_element(count_of_letters.begin(), count_of_letters.end());
    cout << result;
}
