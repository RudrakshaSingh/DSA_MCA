#include <iostream>
using namespace std;

const int maxsize = 100;

int queue[maxsize];
int front = -1, rear = -1;

int visited[maxsize];
int adjMatrix[maxsize][maxsize];
int n;  // Number of vertices

void enqueue(int value) {
    if (rear >= maxsize - 1) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow!" << endl;
        return -1;
    }

    int dequeuedValue = queue[front++];

    if (front > rear) {
        front = rear = -1;
    }

    return dequeuedValue;
}

bool isQueueEmpty() {
    return (front == -1 || front > rear);
}

bool isQueueFull() {
    return (rear == maxsize - 1);
}

void Dfs(int v) {
    cout << v << " ";
    visited[v] = 1;  // Mark node as visited (1)
    for (int i = 0; i < n; i++) {  // Explore all neighbors
        if (adjMatrix[v][i] == 1 && visited[i] == 0) {  // If not visited
            Dfs(i);
        }
    }
}

void bfs(int v) {
    enqueue(v);  // Enqueue the starting vertex
    visited[v] = 1; 
    cout << v << " ";

    while (!isQueueEmpty()) {
        int node = dequeue();  // Dequeue a vertex from the queue
        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] == 1 && visited[i] == 0) {  // If not visited
                visited[i] = 1;  // Mark node as visited
                cout << i << " ";  // Print the visited vertex
                enqueue(i);
            }
        }
    }
}

int main() {
    int m, choice, source;

    cout << "Enter the number of vertices: ";
    cin >> n;

    // Initialize the adjacency matrix to 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (u v) where u and v are vertices connected by an edge:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1; // For undirected graph
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;  // Mark all vertices as unvisited initially
    }

    cout << "\nChoose traversal method:" << endl;
    cout << "1. DFS\n2. BFS" << endl;
    cin >> choice;

    cout << "Enter the source node for traversal: ";
    cin >> source;

    switch (choice) {
        case 1:
            cout << "\nDFS Traversal starting from node " << source << ": ";
            Dfs(source);
            break;
        case 2:
            cout << "\nBFS Traversal starting from node " << source << ": ";
            bfs(source);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
