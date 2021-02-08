#include<bits/stdc++.h>
using namespace std;


/*
Definition: An Eulerian path on a graph is a traversal of the graph that passes through each edge exactly once. It is an Eulerian circuit if it starts and ends at the same vertex.

If a graph admits an Eulerian path, then there are either 0 or 2 vertices with odd degree. If a graph admits an Eulerian circuit, then there are 0 vertices with odd degree.

Theorem: A graph has an Eulerian path if and only if (1) every vertex of degree ≥ 1 lies in the same connected component, and (2) there are 0 or 2 vertices of odd degree.
A graph has an Eulerian circuit if and only if (1) every vertex of degree ≥ 1 lies in the same connected component, and (2) every vertex has even degree.
https://brilliant.org/wiki/eulerian-path/

A directed graph is Eulerian iff every graph vertex has equal indegree and outdegree.
https://mathworld.wolfram.com/EulerianGraph.html
*/

//------------------------------------------------------------------------------

/*
+------------+-------------------------+------------------------------------------------------+
|            | Eulerian Circuit        | Eulerian Path                                        |
+============+=========================+======================================================+
| Undirected |   Every vertex has an   | Either every vertex has even degree                  |
|   Graph    |     even degree         | or exactly 2 vertices have odd degree                |
+------------+-------------------------+------------------------------------------------------+
|  Directed  | Every vertex has equal  | At most 1 vertex with outdegree - indegree == 1 and  |
|   Graph    | indegree and outdegree  | at most 1 vertex with indegree - outdegree == 1 and  |
|            |                         | all other vertices have equal indegree and outdegree |
+------------+-------------------------+------------------------------------------------------+

Note: Additional requirement:-
 all vertices with non zero degree, need to belong to a single connected component
*/

// Hierholzer's algorithm
// O(E) {when we dont use is_connected() and instead use the commented out code of path.size() != edge_count + 1}
class EulerianDirectedGraph {
    int edge_count, n;
    vector<int> in, out, path;
    vector<vector<int>> g;
    int start_nodes, end_nodes;

    void setup() {
        in = vector<int>(n);
        out = vector<int>(n);
        edge_count = 0;

        for (int u = 0; u < n; u++) {
            for(int v : g[u]){
                in[v]++;
                out[u]++;
                edge_count++;
            }
        }
    }

    int find_start_node() {
        int start = 0;
        for (int i = 0; i < n; i++) {
            if(out[i] - in[i] == 1) return i;

            // needed so that start is not to unconnected component with 0 degree
            if(out[i]) start = i;
        }
        return start;
    }

    void dfs(int u) {
        while(out[u]){
            int v = g[u][--out[u]];
            dfs(v);
        }
        path.push_back(u);
    }

    void dfs_connected(int u, vector<bool> &vis) {
        vis[u] = true;
        for(int v : g[u]){
            if(not vis[v]) dfs_connected(v, vis);
        }
    }
    bool is_connected() {
        if(edge_count == 0) return true;
        /*
        vector<vector<int>> tr(n);
        // transverse of graph
        for(int u = 0; u < n; u++) for(int v : g[u]) tr[v].push_back(u);
        */
        vector<bool> vis(n, false);
        int u;
        for(u = 0; u < n; u++) if(out[u]) break;

        dfs_connected(u, vis);
        for(u = 0; u < n; u++) if(not vis[u] and in[u]) return false;
        return true;
    }
public:
    EulerianDirectedGraph(vector<vector<int>> &adj_list) {
        g = adj_list;
        n = g.size();
    }

    bool has_eulerian_path() {
        if(in.empty()) setup();
        if(edge_count == 0) return true;
        if(not is_connected()) return false;

        start_nodes = 0, end_nodes = 0;
        for (int i = 0; i < n; i++) {
            if(abs(in[i] - out[i]) > 1) return false;

            if(out[i] - in[i] == 1) start_nodes++;
            else if(in[i] - out[i] == 1) end_nodes++;
        }
        // if == 0: circuit, if == 1: path
        return (start_nodes == 0 and end_nodes == 0) or (start_nodes == 1 and end_nodes == 1);
    }

    vector<int> get_eulerian_path() {
        assert(has_eulerian_path());

        // instead of is_connected() can use this as well:
        /*
        if(path.size() != edge_count + 1) return {};
        */
        dfs(find_start_node());
        reverse(path.begin(), path.end());
        return path;
    }

    bool has_eulerian_circuit() {
        if(not has_eulerian_path()) return false;
        return (start_nodes == 0 and end_nodes == 0);
    }

    vector<int> get_eulerian_circuit() {
        assert(has_eulerian_circuit());
        return get_eulerian_path();
    }
};

//------------------------------------------------------------------------------

// O(V + E) [+E due to checking connected]
// this is iterative approach
class EulerianUndirectedGraph {
    int edge_count = -1, n, v1, v2;
    int vertex_with_odd_degree;
    vector<int> circuit;
    vector<vector<int>> g;

    void setup() {
        edge_count = 0;
        for(int u = 0; u < n; u++) {
            edge_count += g[u].size();
        }

        // helpful while removing edge
        for(int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
    }

    void dfs(int u, vector<bool> &vis){
        vis[u] = true;
        for(int v : g[u]) if(not vis[v]) dfs(v, vis);
    }

    bool is_connected() {
        vector<bool> vis(n);
        int u;
        for(u = 0; u < n; u++) if(g[u].size()) break;

        dfs(u, vis);

        for(u = 0; u < n; u++) if(not vis[u] and g[u].size()) return false;
        return true;
    }
    int find_start_node() {
        int first = 0;
        while(first < n and !g[first].size()) first++;
        return first;
    }

    void solve() {
        // already solved
        if(circuit.size()) return;

        // add if this is a path, and not circuit, will remove later
        if(v1 != -1 and v2 != -1) {
            g[v1].push_back(v2);
            sort(g[v1].begin(), g[v1].end());
            g[v2].push_back(v1);
            sort(g[v2].begin(), g[v2].end());
        }
        stack<int> st;
        st.push(find_start_node());
        while(st.size()) {
            int u = st.top();
            if(g[u].size() == 0){
                circuit.push_back(u);
                st.pop();
            }
            else{
                int v = g[u].back();
                g[u].pop_back();
                auto it = lower_bound(g[v].begin(), g[v].end(), u);
                /*
                auto i = g[v].begin();
                for(; i != it and i != g[v].end(); i++);
                assert(it == i);
                */
                g[v].erase(it);
                st.push(v);
            }
        }
    }

public:
    EulerianUndirectedGraph(vector<vector<int>> &adj_list) {
        g = adj_list;
        n = g.size();
    }

    bool has_eulerian_path() {
        if(edge_count == -1) setup();
        if(edge_count == 0) return true;
        if(not is_connected()) return false;

        vertex_with_odd_degree = 0;
        v1 = v2 = -1;
        for (int u = 0; u < n; u++) {
            if(g[u].size() % 2 == 0) continue;
            vertex_with_odd_degree++;
            if(v1 == -1) v1 = u;
            else v2 = u;
        }
        return vertex_with_odd_degree == 0 or vertex_with_odd_degree == 2;
    }

    bool has_eulerian_circuit() {
        if(not has_eulerian_path()) return false;
        return vertex_with_odd_degree == 0;
    }

    vector<int> get_eulerian_circuit() {
        assert(has_eulerian_circuit());
        if(circuit.empty()) solve();
        return circuit;
    }
    vector<int> get_eulerian_path() {
        assert(has_eulerian_path());
        if(circuit.empty()) solve();

        vector<int> path;
        for(int i = 0; i < circuit.size()-1; i++){
            if((circuit[i] == v1 and circuit[i+1] == v2) or (circuit[i] == v2 and circuit[i+1] == v1)){
                for(int j = i + 1; j < circuit.size(); j++) path.push_back(circuit[j]);
                for(int j = 1; j <= i; j++) path.push_back(circuit[j]);
                return path;
            }
        }
        // this is a circuit
        return circuit;
    }
};
//------------------------------------------------------------------------------

void addDirectedEdge(vector<vector<int>> &g, int from, int to){
    g[from].push_back(to);
    // g[to].push_back(from);
}
int main(){
    vector<vector<int>> graph(5);

    addDirectedEdge(graph, 1, 2);
    addDirectedEdge(graph, 2, 3);
    // addDirectedEdge(graph, 4, 0);
    addDirectedEdge(graph, 3, 0);
    // addDirectedEdge(graph, 0, 1);


    EulerianDirectedGraph solver(graph);
    vector<int> v = solver.get_eulerian_path();
    cout << v.size() << endl;
    for(int d : v) cout<<d<<' '; cout<<endl;
}

//------------------------------------------------------------------------------
// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; } // To avoid memory leak

     // function to add an edge to graph
    void addEdge(int v, int w);

    // Method to check if this graph is Eulerian or not
    int isEulerian();

    // Method to check if all non-zero degree vertices are connected
    bool isConnected();

    // Function to do DFS starting from v. Used in isConnected();
    void DFSUtil(int v, bool visited[]);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
    // Mark all the vertices as not visited
    bool visited[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;

    // Find a vertex with non-zero degree
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;

    // If there are no edges in the graph, return true
    if (i == V)
        return true;

    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);

    // Check if all non-zero degree vertices are visited
    for (i = 0; i < V; i++)
       if (visited[i] == false && adj[i].size() > 0)
            return false;

    return true;
}

/* The function returns one of the following values
   0 --> If grpah is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;

    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;

    // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;

    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)? 1 : 2;
}
