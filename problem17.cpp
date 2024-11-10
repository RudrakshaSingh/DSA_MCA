#include <bits/stdc++.h>
using namespace std;

const int MAX_VERTICES = 100;
// Structure for edges used in Kruskal's algorithm
struct Edge {
    int u, v, weight;
};

// Kruskal's algorithm
int parent[MAX_VERTICES], Rank[MAX_VERTICES];

int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}

void unionSets(int u, int v) {
    int rootU = findParent(u);
    int rootV = findParent(v);

    if (rootU != rootV) {
        if (Rank[rootU] > Rank[rootV]) {
            parent[rootV] = rootU;
        } else if (Rank[rootU] < Rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            Rank[rootU]++;
        }
    }
}

int kruskal(int n, int m, Edge edges[]) {
    // Initialize the parent and rank for union-find
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }

    // Sort the edges based on weight
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int mstWeight = 0;
    int edgesAdded = 0;
    
    // Process edges to form the MST
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (findParent(u) != findParent(v)) {
            unionSets(u, v);
            mstWeight += weight;
            edgesAdded++;
        }

        if (edgesAdded == n - 1) break;
    }

    return mstWeight;
}

void dijkstra(int n, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int source) {
    int dist[MAX_VERTICES];           //distance array
    int visited[MAX_VERTICES] = {0};  // 0 means unvisited, 1 means visited

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // This loop iterates over all vertices (except the source)
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        // Find the unvisited node with the minimum distance
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = 1;  // Mark node as visited

        // Update distances for the neighbors of u
        for (int v = 0; v < n; v++) {//CHECK EDGE EXIST,CHECK NOT VISITED,,CHECK IF DISTANCE IS STILL NOT INFINITY, CHECK IF IT IS SHORTER
            if (adjMatrix[u][v] != 0 && visited[v] == 0 && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << " is unreachable\n";
        } else {
            cout << "Distance to vertex " << i << " is " << dist[i] << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    // Input edges before selecting the algorithm
    Edge edges[m];
    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Print the edges before the user selects the algorithm
    cout << "\nEntered edges:\n";
    for (int i = 0; i < m; i++) {
        cout << "Edge " << i + 1 << ": " << edges[i].u << " - " << edges[i].v << " (Weight: " << edges[i].weight << ")\n";
    }

    int choice;
    cout << "Choose the algorithm to run:\n";
    cout << "1. Kruskal's Algorithm (Minimum Spanning Tree)\n";
    cout << "2. Dijkstra's Algorithm (Shortest Path)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int mstWeight = kruskal(n, m, edges);
        cout << "The weight of the Minimum Spanning Tree (MST) is: " << mstWeight << endl;

    } else if (choice == 2) {
        int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};  // Initialize all values to 0 (no edges)

        // create adjacency matrix for Dijkstra
        for (int i = 0; i < m; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int weight = edges[i].weight;
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight; // Since the graph is undirected
        }

        int source;
        cout << "Enter the source vertex: ";
        cin >> source;

        dijkstra(n, adjMatrix, source);

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
