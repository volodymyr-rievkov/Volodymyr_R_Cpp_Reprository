#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string song;
    cin >> song;
    vector<string> sub_songs;
    string sub_song;
    for(int i = 0; i < song.size(); i++)
    {
        sub_song = song;
        sub_song.erase(i, 1);
        if(!count(sub_songs.begin(), sub_songs.end(), sub_song))
        {
            sub_songs.push_back(sub_song);
        }
    }
    sub_songs.shrink_to_fit();
    cout << sub_songs.size();
}