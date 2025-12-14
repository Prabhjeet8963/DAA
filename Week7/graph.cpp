#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph 
{
    // Adjacency matrix global variable
    vector<vector<int>> adj_matrix;
public:
    Graph(int n) 
    {
        adj_matrix = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++)
        {
            adj_matrix[i][i] = 0;
        }
    }

    // Function to add an edge between vertices 'u' and 'v'
    void add_edge(int u, int v, int weight) 
    {
        adj_matrix[u][v] = weight;
        adj_matrix[v][u] = weight;
    }

    // Function to add an edge from vertex 'u' to vertex 'v'
    void add_directed_edge(int u, int v, int weight) 
    {
        adj_matrix[u][v] = weight;
    }

    // Function to print the adjacency matrix representation
    void print() 
    {
        cout << "Adjacency Matrix for the Graph:\n";
        int n = adj_matrix.size();
        cout << "  ";
        for (int i = 0; i < n; i++) 
        {
            cout << char(i+97) << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) 
        {
            cout << char(i+97) << " ";
            for (int j = 0; j < n; j++) 
            {
                if(adj_matrix[i][j] == 0)
                    cout << "- ";
                else if(adj_matrix[i][j] == INT_MAX)
                    cout << "& ";
                else
                    cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Return the adjacency matrix
    vector<vector<int>> getMatrix() 
    {
        return adj_matrix;
    }
};

void primsAlgorithm(vector<vector<int>> &graph) 
{
    int numVertices = graph.size();

    vector<int> parent(numVertices, -1);             // Stores how a vertex connects to the MST
    vector<int> minEdgeWeight(numVertices, INT_MAX); // The minimum edge weight for each vertex
    vector<bool> inMST(numVertices, false);          // Whether vertex is included in MST

    minEdgeWeight[0] = 0; 
    for (int edgeCount = 0; edgeCount < numVertices - 1; edgeCount++) 
    {
        // Pick the the smallest edge weight from unexplored vertices
        int minVertex = -1;
        for (int vertex = 0; vertex < numVertices; vertex++) 
        {
            if ((minVertex == -1 || minEdgeWeight[vertex] < minEdgeWeight[minVertex]) && !inMST[vertex])
            {
                minVertex = vertex;
            }
        }
        inMST[minVertex] = true; 

        // Update the table and weights for neighbors of chosen minVertex
        for (int neighbor = 0; neighbor < numVertices; neighbor++) 
        {
            if (graph[minVertex][neighbor] > 0 && !inMST[neighbor] && graph[minVertex][neighbor] < minEdgeWeight[neighbor]) 
            {
                parent[neighbor] = minVertex;
                minEdgeWeight[neighbor] = graph[minVertex][neighbor];
            }
        }
    }

    // Print MST
    int totalCost = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < numVertices; i++) 
    {
        cout << parent[i] << " - " << i << "  (weight = " << minEdgeWeight[i] << ")\n";
        totalCost += minEdgeWeight[i];
    }
    cout << "Total weight of MST = " << totalCost << endl;
    cout << endl;
}

void kruskalsAlgorithm(vector<vector<int>> &graph)
{
    struct Edge { int u, v, w; };

    int V = (int)graph.size();
    vector<Edge> edges;

    // Build undirected edge list (ignore INT_MAX and self-loops)
    for (int u = 0; u < V; u++)
    {
        for (int v = u + 1; v < V; v++)
        {
            int w = graph[u][v];
            if (graph[v][u] < w) w = graph[v][u];  // treat as undirected
            if (w != INT_MAX)
            {
                Edge e; e.u = u; e.v = v; e.w = w;
                edges.push_back(e);
            }
        }
    }

    // ---- Selection sort by weight (no std::sort) ----
    int n = (int)edges.size();
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (edges[j].w < edges[minIdx].w)
                minIdx = j;
        }
        if (minIdx != i)
        {
            Edge tmp = edges[i];
            edges[i] = edges[minIdx];
            edges[minIdx] = tmp;
        }
    }

    // ---- Disjoint Set Union (Union–Find) ----
    vector<int> parent(V), rnk(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    // find with path compression
    // Note: we pass vectors by reference via globals or static lambdas are disallowed;
    // so we implement as local static functions using structs or lambdas are avoided by inlining.
    // Here we implement small helpers inside the function using static to avoid captures.
    struct UF {
        static int find_set(int v, vector<int>& parent) {
            if (parent[v] == v) return v;
            parent[v] = find_set(parent[v], parent);
            return parent[v];
        }
        static bool union_sets(int a, int b, vector<int>& parent, vector<int>& rnk) {
            a = find_set(a, parent);
            b = find_set(b, parent);
            if (a == b) return false;
            if (rnk[a] < rnk[b]) {
                int t = a; a = b; b = t;
            }
            parent[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
            return true;
        }
    };

    // ---- Kruskal: pick smallest edges that don't form a cycle ----
    vector<Edge> mst;
    int total = 0;

    for (int i = 0; i < n && (int)mst.size() < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (UF::union_sets(u, v, parent, rnk))
        {
            mst.push_back(edges[i]);
            total += w;
        }
    }

    // ---- Output ----
    if ((int)mst.size() != V - 1)
    {
        cout << "MST not possible (graph is disconnected)." << endl << endl;
        return;
    }

    cout << "Edges in MST (Kruskal):" << endl;
    for (int i = 0; i < (int)mst.size(); i++)
    {
        cout << char(mst[i].u + 97) << " - " << char(mst[i].v + 97)
             << "  (weight = " << mst[i].w << ")" << endl;
    }
    cout << "Total weight of MST = " << total << endl << endl;
}

void bellmanFord(vector<vector<int>> &graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 1: Relax all edges V-1 times
    for (int count = 1; count <= V - 1; count++) 
    {
        for (int u = 0; u < V; u++) 
        {
            for (int v = 0; v < V; v++) 
            {
                if (graph[u][v] != INT_MAX && dist[u] != INT_MAX 
                    && dist[u] + graph[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Step 2: Check for negative weight cycles
    for (int u = 0; u < V; u++) 
    {
        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] != INT_MAX && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
            {
                cout << "Graph contains a negative weight cycle!\n";
                return;
            }
        }
    }

    // Step 3: Print the results
    cout << "Vertex Distance from Source (" << char(src + 97) << "):\n";
    for (int i = 0; i < V; i++) 
    {
        cout << char(i + 97) << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
    cout << endl;
}


void floydWarshall(vector<vector<int>> &dist) 
{
    int V = dist.size();

    for (int k = 0; k < V; k++) 
    {
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                // Check to avoid overflow and invalid sums
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    cout << "  ";
    for (int i = 0; i < V; i++) 
    {
        cout << char(i+97) << " ";
    }
    for (int i = 0; i < V; i++) 
    {
        cout << endl << char(i+97) << " ";
        for (int j = 0; j < V; j++) 
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
    }
    cout << endl;
}


int main() 
{

    int n = 5;
    Graph g(n);

    g.add_directed_edge(0, 1, -1);
    g.add_directed_edge(0, 2, 4);
    g.add_directed_edge(1, 2, 3);
    g.add_directed_edge(1, 3, 2);
    g.add_directed_edge(3, 4, -3);
    g.add_directed_edge(4, 2, 5);
    g.add_directed_edge(1, 4, 2);
    g.add_directed_edge(4, 1, 1);

    g.print();

    vector<vector<int>> adjMatrix = g.getMatrix();
    bellmanFord(adjMatrix, 0);

    return 0;
}
