#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int n, k, a, b; 
    cin >> n >> k >> a >> b; 
    int max = a;
    int min = a; 
    if(k == 0) 
    { 
        cout << max << " " << min; 
        return 0; 
    } 
    int day = 1;
    while(max + k - k * (n - day - 1) <= b) 
    { 
        max += k; 
        day++; 
    } 
    int result_max = max; 
    for(int i = 1; i <= k; i++) 
    { 
        if(max + i - k * (n - day - 1) <= b) 
        { 
            result_max++; 
        } 
    } 
    day = 1; 
    while(min - k + k * (n - day - 1) >= b) 
    { 
        min -= k; 
        day++; 
    } 
    int result_min = min; 
    for(int i = 1; i <= k; i++) 
    { 
        if(min - i + k * (n - day - 1) >= b) 
        { 
            result_min--; 
        } 
    } 
    cout << result_max << ' ' << result_min; 
}