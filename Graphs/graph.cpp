#include "graph.h"
#include <stack>


using namespace std;


void error(string msg) { cout << msg << endl; }

DisjointSet::DisjointSet(int numVertices) : subsets(size_t(numVertices)) 
{
    for (int i = 0; i < numVertices; ++i)
        makeSet(i);
}

void DisjointSet::makeSet(Vertex x) 
{
    subsets[x] = Set{x};
}

Vertex DisjointSet::findSet(Vertex x)
{
    int parent = subsets[x].parent;
    if (x == parent)
        return x;
    subsets[x].parent = findSet(parent);
    return subsets[x].parent;
}

void DisjointSet::unionSets(Vertex x, Vertex y)
{
    x = findSet(x);
    y = findSet(y);
    if (x != y)
        subsets[y].parent = x;
}


Graph Graph::sort_edges() const
{
    Graph cpy(*this);
    std::sort(cpy.begin(), cpy.end());
    return cpy;
}

VertexList Graph::edges_from(Vertex vertex) const
{
    VertexList v;
    for (auto edge : *this)
    {
        if (edge.u == vertex)
            v.push_back(edge.v);
    }

    return v;
}


EdgeList Kruskals(const Graph& G)
{
    DisjointSet ds{G.numVertices};
    const Graph& sorted_edges = G.sort_edges();
    size_t size = G.numVertices - 1;
    EdgeList minTree;

    for (auto e : sorted_edges)
    {
        Vertex u = ds.findSet(e.u);
        Vertex v = ds.findSet(e.v);
        
        if (u != v)
        {
            ds.unionSets(u, v);
            minTree.push_back(e);
            if (minTree.size() >= size)
                break;
        }
    }

    return minTree;
}


int sum_weights(EdgeList const& L)
{
    return std::accumulate(L.begin(), L.end(), 0, 
    [](int accumulated, const Edge& e)
    {
        return accumulated + e.weight;
    });
}

void file_to_graph(string filename, Graph & G)
{
    ifstream file{filename};
    file >> G;
}

VertexList dfs(const Graph& graph, Vertex startVertex)
{
    VertexList result;
    vector<bool> visited(graph.size(), false);
    stack<Vertex> s;
    visited[startVertex] = true;
    s.push(startVertex);

    while (!s.empty())
    {
        startVertex = s.top();
        s.pop();
        result.push_back(startVertex);
        for (Vertex v : graph.edges_from(startVertex))
        {
            if (!visited[v])
            {
                visited[v] = true;
                s.push(v);
            }
        }
    }

    return result;
}

VertexList bfs(const Graph& graph, Vertex startVertex)
{
    VertexList result;
    vector<bool> visited(graph.size(), false);
    queue<Vertex> q;
    visited[startVertex] = true;
    q.push(startVertex);
    while (!q.empty())
    {
        startVertex = q.front();
        q.pop();
        result.push_back(startVertex);
        for (Vertex v : graph.edges_from(startVertex))
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return result;
}

string get_arg(int argc, char *argv[], string def)
{
    if (argc > 1) return argv[1];
    return def;
}
