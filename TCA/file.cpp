#include <iostream>
#include <vector>

using namespace std;

int countWays(int N) {
    vector<int> dp(N + 1);
    dp[0] = dp[1] = 1;
    
    if (N >= 2)
        dp[2] = 2;

    for (int i = 3; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;

    cout << countWays(N) << endl;

    return 0;
}