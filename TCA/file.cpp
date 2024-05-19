#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1234567891;

void count_paths(int n, int m, int a, int b, const vector<pair<int, int>>& edges) 
{
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    for(const auto& edge : edges) 
    {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        in_degree[v]++;
    }
    vector<int> topo_order;
    queue<int> q;
    for(int i = 1; i <= n; ++i) 
    {
        if (in_degree[i] == 0) 
        {
            q.push(i);
        }
    }
    while(!q.empty()) 
    {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for(int v : graph[u]) 
        {
            in_degree[v]--;
            if(in_degree[v] == 0) 
            {
                q.push(v);
            }
        }
    }
    vector<long long> dp(n + 1, 0);
    dp[a] = 1;
    for(int u : topo_order) 
    {
        for(int v : graph[u]) 
        {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    cout << dp[b] << endl;
}

int main() 
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<pair<int, int>> edges(m, 0);
    for(int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        edges[i].first = u;
        edges[i].second = v;
    }
    count_paths(n, m, a, b, edges);
}