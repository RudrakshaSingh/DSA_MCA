#include <iostream>
#include <cstdlib>
using namespace std;

// Global variables for Queue
int* queue;
int front = -1, rear = -1, queue_capacity;

// Global visited array and adjacency matrix
int* visited;
int** adjMatrix;
int n;  // Number of vertices

void enqueue(int value) {
    if (rear >= queue_capacity - 1) {
        cout << "Queue Overflow!" << endl;
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow!" << endl;
        return -1;
    }

    int dequeuedValue = queue[front++];

    // If the queue becomes empty after dequeuing, reset front and rear
    if (front > rear) {
        front = rear = -1;
    }

    return dequeuedValue;
}

bool isQueueEmpty() {
    return (front == -1 || front > rear);
}

bool isQueueFull() {
    return (rear == queue_capacity - 1);
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

    // Dynamically allocate memory for the adjacency matrix
    adjMatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize the adjacency matrix to 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    cout << "Enter the number of edges: ";
    cin >> m;

    // User input for the edges
    cout << "Enter the edges (u v) where u and v are vertices connected by an edge:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1; // For undirected graph
    }

    visited = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        visited[i] = 0;  // Mark all vertices as unvisited initially
    }

    queue_capacity = n;
    queue = (int*)malloc(queue_capacity * sizeof(int));

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

    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    free(visited);
    free(queue);

    return 0;
}
