#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * front = nullptr;
Node * rear = nullptr;

Node * createNode(int val) {
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = nullptr;
    return newNode;
}

void EnqueueLL(int val) {
    Node * newNode = createNode(val);

    if (front == nullptr) {
        front = rear = newNode;
        rear -> next = front;
    } else {
        rear -> next = newNode;
        rear = newNode;
        rear -> next = front;
    }
    cout << val << " added to queue." << endl;
}

void DequeueLL() {
    if (front == nullptr) {
        cout << "Queue Underflow" << endl;
        return;
    }
    Node * temp = front;
    cout << "Dequeued element is " << temp -> data << endl;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front -> next;
        rear -> next = front;
    }
    free(temp);
}

int getFrontLL() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front -> data;
}

bool isEmptyLL() {
    return (front == nullptr);
}

int CurrentSizeLL() {
    if (isEmptyLL())
        return 0;
    int size = 0;
    Node * temp = front;
    do {
        size++;
        temp = temp -> next;
    } while (temp != front);
    return size;
}

int queue[100];
int maxSize, frontA, rearA;

void createQueue() {
    cout << "Enter the size of the Queue (max 100): ";
    cin >> maxSize;
    if (maxSize > 100 || maxSize <= 0) {
        cout << "Invalid size. Setting queue size to 100." << endl;
        maxSize = 100;
    }
    frontA = rearA = -1;
}

void Enqueue(int val) {
    if ((rearA + 1) % maxSize == frontA) {
        cout << "Queue Overflow" << endl;
    } else {
        if (frontA == -1) { // If the queue is empty
            frontA = 0;
        }
        rearA = (rearA + 1) % maxSize;
        queue[rearA] = val;
        cout << val << " added to queue." << endl;
    }
}

void Dequeue() {
    if (frontA == -1) {
        cout << "Queue Underflow" << endl;
    } else {
        cout << "Dequeued element is " << queue[frontA] << endl;
        if (frontA == rearA) { // If the queue becomes empty
            frontA = rearA = -1;
        } else {
            frontA = (frontA + 1) % maxSize;
        }
    }
}

int getFront() {
    if (frontA == -1) {
        cout << "Queue is empty." << endl;
        return -1;
    } else {
        return queue[frontA];
    }
}

bool isEmpty() {
    return (frontA == -1);
}

bool isFull() {
    return ((rearA + 1) % maxSize == frontA);
}

int CurrentSize() {
    if (isEmpty())
        return 0;
    return (rearA - frontA + maxSize) % maxSize + 1;
}

int main() {
    int k;
    cout << "How to make queue enter 1 for LL and 2 for Array" << endl;
    cin >> k;
    if (k == 1) {
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
                EnqueueLL(val);
                break;
            case 2:
                DequeueLL();
                break;
            case 3:
                cout << "Front element is: " << getFrontLL() << endl;
                break;
            case 4:
                cout << (isEmptyLL() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 5:
                cout << "Queue size: " << CurrentSizeLL() << endl;
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
    } else if (k == 2) {
        int ch, val;
        cout << "Creating Queue :" << endl;
        createQueue();
        cout << "QUEUE CREATED" << endl;
        cout << endl;

        bool conti = true;
        while (conti) {
            cout << "=================================================================================" << endl;

            cout << "(1) Enqueue in Queue             ";
            cout << "(2) Dequeue from Queue           ";
            cout << "(3) Peek at front element        " << endl;
            cout << "(4) Check if Queue is empty      ";
            cout << "(5) Check if Queue is full       ";
            cout << "(6) Get queue size               " << endl;

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
                cout << (isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 6:
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
    } else {
        cout << "invalid exiting program" << endl;
    }

    return 0;
}