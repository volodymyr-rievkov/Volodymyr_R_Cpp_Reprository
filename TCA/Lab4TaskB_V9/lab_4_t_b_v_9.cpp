#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
    visited[v] = true;
    count++;
    for(int vertex : graph[v]) 
    {
        if (!visited[vertex]) {
            dfs(vertex, graph, visited, count);
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++) 
    {
        int a, b;
        cin >> a >> b;
        a; b;
        graph[a].push_back(b);
    }
    int result = 0;
    for(int i = 0; i < n; i++) 
    {
        vector<bool> visited(n + 1, false);
        int count = 0;
        dfs(i, graph, visited, count);
        result += count - 1;
    }
    cout << result << endl;
}