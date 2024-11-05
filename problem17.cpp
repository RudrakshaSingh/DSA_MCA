#include <bits/stdc++.h>
using namespace std;

// Function to print the adjacency list
void printAdjList(const unordered_map<int, vector<pair<int, int>>> &adjList) {
    cout << "Adjacency List:\n";
    for (const auto &pair : adjList) {
        cout << pair.first << ": ";
        for (const auto &neighbor : pair.second) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") "; // (neighbor, weight)
        }
        cout << endl;
    }
}

// Function to prepare the adjacency list from edges
void prepareAdjList(unordered_map<int, vector<pair<int, int>>> &adj, const vector<vector<int>> &edges) {
    for (const auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Because it's an undirected graph
    }
}

vector<int> dijkstra(int v, unordered_map<int, vector<pair<int, int>>> &adj, int s) {
    vector<int> dist(v);//no of vertices
    for (int i = 0; i < v; i++)
    {
        dist[i]=INT_MAX;//making every distance to max
    }

    set<pair<int,int>> st;
    dist[s]=0;
    st.insert(make_pair(0,s));

    while(!st.empty())
    {//fetch top record
        auto top = *(st.begin());//st.begin() returns an iterator pointing to the first element * for dereference
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(st.begin());//remove top record

        //traverse on neighbours
        for (auto neighbour : adj[topNode]){
            if (nodeDistance + neighbour.second < dist[neighbour.first]){
                //update distance
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                if(record!=st.end()){//if found
                    st.erase(record);
                }
                //update
                dist[neighbour.first]=nodeDistance+neighbour.second;
                //push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist; 
}

// Find function for union-find (Disjoint Set)
int findParent(vector<int> &parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent,parent[node]); // Path compression
}

// Union function for union-find (Disjoint Set)
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent,u);
    v = findParent(parent,v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

// Kruskal’s Minimum Spanning Tree Algorithm
int kruskalMST(int n, vector<vector<int>>& edges) {
    // Sorting edges based on their weights
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank,n);

    int minWeight = 0;
    for(int i=0;i<edges.size();i++){
        int u = findParent( parent,edges[i][0]);
        int v = findParent( parent,edges[i][1]);
        int wt=edges[i][2];
        if(u!=v){
            minWeight+=wt;
            unionSets(u,v,parent,rank);
        }
    }

    return minWeight;
}

// Function to print edges
void printEdges(const vector<vector<int>>& edges) {
    cout << "Edges List:\n";
    for (const auto& edge : edges) {
        cout << edge[0] << " -- " << edge[1] << " with weight " << edge[2] << endl;
    }
}

int main() {
    int n; // number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;
    int m; // number of edges
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges; // Store edges as {u, v, weight}
    unordered_map<int, vector<pair<int, int>>> adj; // adjacency list

    for (int i = 0; i < m; i++) {
        cout << "Enter edges (u v weight): ";
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Prepare adjacency list
    prepareAdjList(adj, edges);

    // Print the adjacency list
    printAdjList(adj);
    // Print the edges
    printEdges(edges);

    int choice;
    cout << "Choose Algorithm:" << endl;
    cout << "1. Dijkstra's Shortest Path Algorithm" << endl;
    cout << "2. Kruskal's Minimum Spanning Tree Algorithm" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int source;
            cout << "Enter the source vertex: ";
            cin >> source;
            vector<int> distances = dijkstra(n, adj, source); // Pass the adjacency list to Dijkstra
            cout << "Shortest distances from source " << source << ": ";
            for (int i = 0; i < distances.size(); i++) {
                cout << distances[i] << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            int minCost = kruskalMST(n, edges);
            cout << "Minimum cost of the spanning tree: " << minCost << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    return 0;
}

// 5
// 7
// 0 1 7
// 0 2 1
// 0 3 2
// 1 2 3
// 1 3 5
// 1 4 1
// 3 4 7
//op=1 3 0 3 4