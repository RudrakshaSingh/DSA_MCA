#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Enqueue function for circular queue
void Enqueue(int val) {
    Node* newNode = createNode(val);
    
    if (front == nullptr) { 
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode; 
        rear = newNode; 
        rear->next = front; 
    }
    cout << val << " added to queue." << endl;
}

void Dequeue() {
    if (front == nullptr) { 
        cout << "Queue Underflow" << endl;
        return;
    }
    Node* temp = front; 
    cout << "Dequeued element is " << temp->data << endl;

    if (front == rear) { 
        front = rear = nullptr; 
    } else {
        front = front->next; 
        rear->next = front; 
    }
    free(temp); 
}

int getFront() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front->data;
}

bool isEmpty() {
    return (front == nullptr);
}

int CurrentSize() {
    if (isEmpty()) return 0; 
    int size = 0;
    Node* temp = front;
    do {
        size++;
        temp = temp->next; 
    } while (temp != front); 
    return size;
}

// Main function
int main() {
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
