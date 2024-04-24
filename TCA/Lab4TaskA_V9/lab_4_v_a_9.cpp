#include <iostream>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& graph, int start, vector<bool>& visited) 
{
    vector<int> queue;
    queue.push_back(start);
    visited[start] = true;
    int front = 0;
    while (front < queue.size()) 
    {
        int node = queue[front++];
        for(int neighbor : graph[node])
         {
            if (!visited[neighbor]) 
            {
                queue.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() 
{
    int n;
    int m;
    cin >> n >> m;
    if(n < 1 || n > 1e4 || m < 1 || m > 1e4)
    {
        return 0;
    }
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a < 1 || a > n || b < 1 || b > n)
        {
            return 0;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int connections = 0;
    vector<bool> visited(n + 1, false);
    for(int city = 1; city <= n; city++) 
    {
        if (!visited[city])
        {
            connections++;
            bfs(graph, city, visited);
        }
    }
    cout << connections - 1 << endl;
}