#include<iostream>
#include<vector>
using namespace std;

struct edge
{
    int start;
    int end;
    int value ;
};

void set_graph_and_values(int &graph_vertices, int &graph_edges, vector<edge> &graph)
{
    do
    {
        cout << "Enter amount of graph vertices: ";
        cin >> graph_vertices;
        if(graph_vertices < 1)
        {
            cout << "Amount of graph vertices must be greater that 0." << endl;
        }
    }while (graph_vertices < 1);
    do
    {
        cout << "Enter amount of graph edges: ";
        cin >> graph_edges;
        if(graph_edges < 1)
        {
            cout << "Amount of graph edges must be greater that 0." << endl;
        }
    }while (graph_edges < 1);
    cout << "Enter start vertex, end vertex and destiantion of graph edge." << endl;
    for(int i = 0; i < graph_edges; i++)
    {
        edge edge;
        do
        {
            cin >> edge.start >> edge.end >> edge.value;
            if(edge.start < 1 || edge.start > graph_vertices || edge.end < 1 || edge.end > graph_vertices || edge.value < 1)
            {
                cout << "Vertices should be in range(0" << " - " << graph_vertices << ")!" << endl << "Destination must ber greater than 0!" << endl;
            }
            if (edge.start == edge.end) 
            {
                cout << "Start and end vertices of an edge cannot be the same." << endl;
            }
        }while (edge.start < 1 || edge.start > graph_vertices || edge.end < 1 || edge.end > graph_vertices || edge.value < 1);
        graph.push_back(edge);
    }
    graph.shrink_to_fit();
}

void print_graph(const int graph_vertices, const int graph_edges, const vector<edge> &graph)
{
    cout << "Vertices: " << graph_vertices << endl;
    cout << "Edges: " << graph_edges << endl;
    cout << "Graph: " << endl;
    for(int i = 0; i < graph_edges; i++)
    {
        cout << graph[i].start << "--" << graph[i].end << " = " << graph[i].value << endl;
    }
}

void set_start_vertex(const int graph_vertices, int &start)
{
    do
    {
        cout << "Enter start vertex(1 - " << graph_vertices << "): ";
        cin >> start; 
        if(start < 1 || start > graph_vertices)
        {
            cout << "Error: Value is out of range." << endl;
        }
    } while (start < 1 || start > graph_vertices);
    
    
}

void dijkstra_algorithm(const int graph_vertices, const int graph_edges, const vector<edge> &graph, vector<int> &result, int start_vertex)
{
    vector<bool> visited(graph_vertices + 1, false);
    for(int i = 0; i <= graph_vertices; i++)
    {
        result.push_back(INT_MAX);
    }
    result.shrink_to_fit();
    result[start_vertex] = 0;
    visited[start_vertex] = true;
    int start_value = 0;
    for(int v = 0; v < graph_vertices; v++)
    {    
        for(int i = 0; i < graph_edges; i++)
        {
            if(graph[i].start == start_vertex && !visited[graph[i].end])
            {
                if(result[graph[i].end] > graph[i].value + start_value)
                {
                    result[graph[i].end] = graph[i].value + start_value;
                }
            }
            else if(graph[i].end == start_vertex && !visited[graph[i].start])
            {
                if(result[graph[i].start] > graph[i].value + start_value)
                {
                    result[graph[i].start] = graph[i].value + start_value;
                }
            }
        }
        start_value = INT_MAX;
        for(int i = 1; i <= graph_vertices; i++)
        {
            if(result[i] < start_value && !visited[i])
            {
                start_value = result[i];
                start_vertex = i;
            }
        }
        visited[start_vertex] = true;
    }
}

void print_destinations(const int start, const int graph_vertices, const vector<int> &graph)
{
    for(int i = 1; i <= graph_vertices; i++)
    {
        cout << start << "--" << i << " = " << graph[i] << endl;
    }
}

int main()
{
    int graph_vertices;
    int graph_edges;
    vector<edge> graph;
    set_graph_and_values(graph_vertices, graph_edges, graph);
    print_graph(graph_vertices, graph_edges, graph);
    vector<int> result;
    cout << "Dijkstra algorithm: " << endl;
    int start;
    set_start_vertex(graph_vertices, start);
    dijkstra_algorithm(graph_vertices, graph_edges, graph, result, start);
    print_destinations(start, graph_vertices, result);
}
// 30
// 49
// 1 2 8
// 2 3 4
// 3 4 6
// 4 5 1
// 5 6 1
// 7 8 2
// 8 9 1
// 9 10 7
// 10 11 7
// 11 12 5
// 13 14 1
// 14 15 4
// 15 16 3
// 16 17 6
// 17 18 2
// 19 20 3
// 20 21 7
// 21 22 1
// 22 23 3
// 23 24 5
// 25 26 4 
// 26 27 2 
// 27 28 7
// 28 29 7
// 29 30 3
// 1 7 4
// 2 8 5
// 3 9 3
// 4 10 2
// 5 11 1
// 6 12 8
// 7 13 3
// 8 14 3
// 9 15 1
// 10 16 7
// 11 17 7 
// 12 18 1
// 13 19 4
// 14 20 2
// 15 21 3
// 16 22 5
// 17 23 8
// 18 24 8
// 19 25 7
// 20 26 1
// 21 27 3
// 22 28 4
// 23 29 3
// 24 30 1