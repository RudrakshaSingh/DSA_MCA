#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, unordered_map<int, vector<int>> &adjList) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); //  graph
}

void prepareAdjList(unordered_map<int, vector<int>> &adjList, vector<pair<int, int>> edges) {
    for (auto edge : edges) {
        addEdge(edge.first, edge.second, adjList);
    }
}

// Function to print the adjacency list
void printAdjList(const unordered_map<int, vector<int>> &adjList) {
    cout << "Adjacency List:" << endl;
    for (const auto &pair : adjList) {
        cout << pair.first << ": ";
        for (int neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

// Function to perform BFS traversal from a given starting vertex
void bfs(int start, unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        ans.push_back(vertex); // Store the result of BFS

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to perform BFS on the entire graph
vector<int> BFS(int vertex, unordered_map<int, vector<int>> &adjList) {
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Traverse all components of the graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(i, adjList, visited, ans);
        }
    }
    return ans;
}

// Function to perform DFS traversal from a given starting vertex
void dfs(int vertex, unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans) {
    visited[vertex] = true;
    ans.push_back(vertex); // Store the result of DFS

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, ans);
        }
    }
}

// Function to perform DFS on the entire graph
vector<int> DFS(int vertex, unordered_map<int, vector<int>> &adjList) {
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Traverse all components of the graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited, ans);
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of vertices: " ;
    cin >> n;
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int>> edges;
    
    for (int i = 0; i < m; i++) {
        cout << "Enter edges (u v): ";
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    // Prepare adjacency list
    unordered_map<int, vector<int>> adjList;
    prepareAdjList(adjList, edges);

    // Print adjacency list
    printAdjList(adjList);

    int choice;
    cout << "Choose Traversal Method:" << endl;
    cout << "1. BFS" << endl;
    cout << "2. DFS" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    vector<int> ans;

    switch (choice) {
    case 1: // BFS
        ans = BFS(n, adjList);
        cout << "BFS Traversal Order: ";
        break;
    case 2: // DFS
        ans = DFS(n, adjList);
        cout << "DFS Traversal Order: ";
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 0;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
