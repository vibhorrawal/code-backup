/*
Definition: An Eulerian path on a graph is a traversal of the graph that passes through each edge exactly once. It is an Eulerian circuit if it starts and ends at the same vertex.

If a graph admits an Eulerian path, then there are either 0 or 2 vertices with odd degree. If a graph admits an Eulerian circuit, then there are 0 vertices with odd degree.

Theorem: A graph has an Eulerian path if and only if (1) every vertex of degree ≥ 1 lies in the same connected component, and (2) there are 0 or 2 vertices of odd degree.
A graph has an Eulerian circuit if and only if (1) every vertex of degree ≥ 1 lies in the same connected component, and (2) every vertex has even degree.
https://brilliant.org/wiki/eulerian-path/

A directed graph is Eulerian iff every graph vertex has equal indegree and outdegree.
https://mathworld.wolfram.com/EulerianGraph.html
*/

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


