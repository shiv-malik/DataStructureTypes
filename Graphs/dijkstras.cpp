#include "dijkstras.h"
#include <algorithm>
#include <compare>
using namespace std;

struct Element
{
    int first, second;

    std::strong_ordering operator<=>(const Element& other) const
    {
        return second <=> other.second;
    }
};

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int numVertices = G.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    minHeap.push({source, 0});
    
    while (!minHeap.empty())
    {
        int u = minHeap.top().first;
        minHeap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        
        for (Edge edge: G[u])
        {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
            
        }
    }

    return distances;

}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at])
        path.push_back(at);

    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total)
{
    for (int i : v)
        cout << i << " ";
    cout << endl << "Total cost is " << total << endl;
}