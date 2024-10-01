#include <iostream>
#include <cstdlib> // For malloc and free
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    Node* front;
    Node* rear;
};

// Create a global queue variable
Queue q;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Function to enqueue an element
void Enqueue(int val) {
    Node* newNode = createNode(val);
    if (!newNode) { // Check if the new node was successfully created
        return; // Do not proceed if memory allocation failed
    }
    if (q.rear == nullptr) { // Queue is empty
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode; // Add the new node at the end
        q.rear = newNode; // Update the rear
    }
    cout << val << " added to queue." << endl;
}

// Function to dequeue an element
void Dequeue() {
    if (q.front == nullptr) { // Check for underflow
        cout << "Queue Underflow" << endl;
        return;
    }
    Node* temp = q.front; // Get the front node
    cout << "Dequeued element is " << temp->data << endl;
    q.front = q.front->next; // Move front to the next node

    if (q.front == nullptr) { // If queue is now empty
        q.rear = nullptr; // Update rear to nullptr
    }

    free(temp); // Free the dequeued node
}

// Function to get the front element
int getFront() {
    if (q.front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return q.front->data;
}

// Function to check if the queue is empty
bool isEmpty() {
    return (q.front == nullptr); // Queue is empty if front is nullptr
}

// Function to get the current size of the queue
int CurrentSize() {
    int size = 0;
    Node* temp = q.front;
    while (temp) {
        size++;
        temp = temp->next; // Move to the next node
    }
    return size;
}

// Main function
int main() {
    q.front = q.rear = nullptr; // Initialize front and rear to nullptr
    int ch, val;
    bool conti = true;

    while (conti) {
        cout << "=================================================================================" << endl;
        cout << "(1) Enqueue in Queue             ";
        cout << "(2) Dequeue from Queue           ";
        cout << "(3) Peek at front element        " << endl;
        cout << "(4) Check if Queue is empty      ";
        cout << "(5) Get queue size               " << endl;

        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter value to be enqueued: ";
            cin >> val;
            Enqueue(val);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            cout << "Front element is: " << getFront() << endl;
            break;
        case 4:
            cout << (isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
            break;
        case 5:
            cout << "Queue size: " << CurrentSize() << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }

        cout << endl;
        char choice;
        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
        conti = (choice == 'y' || choice == 'Y');
    }

    return 0;
}
