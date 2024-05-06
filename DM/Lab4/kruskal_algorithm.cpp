using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

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

bool compare_edges(const edge &first, const edge &second)
{
    return first.value < second.value;
}

int find(int vertex, vector<int> &parents)
{
    if(parents[vertex] == vertex)
    {
        return vertex;
    }
    return find(parents[vertex], parents);
}

void kruskal_algorithm(const int graph_vertices, const int graph_edges, vector<edge> &graph, vector<edge> &result)
{
    sort(graph.begin(), graph.end(), compare_edges);
    vector<int> parents(graph_vertices + 1);
    for(int i = 0; i <= graph_vertices; i++)
    {
        parents[i] = i;
    }
    for(int i = 0; i < graph_edges; i++) 
    {
        int start_parent = find(graph[i].start, parents);
        int end_parent = find(graph[i].end, parents);
        if(start_parent != end_parent)
        {
            result.push_back(graph[i]);
            parents[start_parent] = end_parent;
        }
    }
    result.shrink_to_fit();
}

int get_graph_weight(int graph_edges, vector<edge> &graph)
{
    int sum = 0;
    for(int i = 0; i < graph_edges; i++)
    {
        sum += graph[i].value;
    }
    return sum;
}

int main()
{
    int graph_vertices;
    int graph_edges;
    vector<edge> graph;
    set_graph_and_values(graph_vertices, graph_edges, graph);
    print_graph(graph_vertices, graph_edges, graph);
    vector<edge> result;
    cout << "Kruskal algorithm: " << endl;
    kruskal_algorithm(graph_vertices, graph_edges, graph, result);
    print_graph(graph_vertices, result.size(), result);
    cout << "Minimum spanning tree: " << get_graph_weight(result.size(), result);
}