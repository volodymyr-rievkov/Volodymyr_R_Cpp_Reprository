#include<iostream>
#include<string.h>
using namespace std;

const int t_size = 3;
const char* variant = "A152";
char text[t_size];

void get_text()
{
    cin.getline(text, t_size);
}

bool is_word_special(char* word)
{
    if((word[0] == 'A' || word[0] == 'a') && (word[strlen(word) - 1] == 'A'  || word[strlen(word) - 1] == 'a'))
    {
        for(int i = 0; i < strlen(word); i++)
        {
            if(word[i] != toupper(word[i]))
            {
                return false;
            }
        }
        for(int i = 0; i < strlen(word) - 1; i++)
        {
            if(word[i] == word[i + 1])
            {
                return true;
            }
        }    
    }
    return false;
}

int get_specail_words_count()
{
    int count = 0;
    char* token;
    token = strtok(text, " ");
    if(is_word_special(token))
    {
        count++;
    }
    while(token != NULL)
    {
        token = strtok(NULL, " ");
        if(token != NULL && is_word_special(token))
        {
            count++;
        }
    }
    return count;
}

void print_result()
{
    cout << variant << " " << get_specail_words_count();
}

int main()
{
    get_text();
    if(strlen(text) <= t_size)
    {
        print_result();
    }
}