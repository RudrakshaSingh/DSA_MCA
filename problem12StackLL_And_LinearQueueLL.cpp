#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * head = nullptr;

int getSize() {
    int count = 0;
    Node * temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp -> next;
    }
    return count;
}

void push(int val) {

    Node * newNode = (Node * ) malloc(sizeof(Node));

    newNode -> data = val;
    newNode -> next = head;
    head = newNode;
    cout << val << " pushed to stack." << endl;
}

void pop() {
    if (head == nullptr) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "The popped element is " << head -> data << endl;
    Node * temp = head;
    head = head -> next;
    free(temp);
}

int peek() {
    if (head == nullptr) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return head -> data;
}

bool isEmpty() {
    return head == nullptr;
}

Node * front = nullptr;
Node * rear = nullptr;

Node * createNode(int val) {
    Node * newNode = (Node * ) malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = nullptr;
    return newNode;
}

void Enqueue(int val) {
    Node * newNode = createNode(val);

    if (rear == nullptr) { // Queue is empty
        front = rear = newNode;
    } else {
        rear -> next = newNode;
        rear = newNode;
    }
    cout << val << " added to queue." << endl;
}

void Dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow" << endl;
        return;
    }
    Node * temp = front;
    cout << "Dequeued element is " << temp -> data << endl;
    front = front -> next;

    if (front == nullptr) { // If queue is now empty
        rear = nullptr;
    }

    free(temp); // Free the dequeued node
}

int getFront() {
    if (front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front -> data;
}

bool isEmptyQ() {
    return (front == nullptr);
}

int CurrentSize() {
    int size = 0;
    Node * temp = front;
    while (temp) {
        size++;
        temp = temp -> next;
    }
    return size;
}

int main() {
    int k;
    cout << "How to make queue enter " << endl << "     1 for Stack using LL " << endl << "     2 for queue using LL" << endl;
    cin >> k;
    if (k == 1) {
        int ch, val;
        cout << "STACK CREATED" << endl;
        cout << endl;

        bool conti = true;
        while (conti) {
            cout << "==========================================================" << endl;

            cout << "(1) Push in stack             ";
            cout << "(2) Pop from stack             ";
            cout << "(3) Peek at top element" << endl;
            cout << "(4) Check if stack is empty   ";
            cout << "(5) Get stack size" << endl;

            cout << "Enter choice: ";
            cin >> ch;
            switch (ch) {
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3: {
                int topElement = peek();
                if (topElement != -1) {
                    cout << "Top element is: " << topElement << endl;
                }
                break;
            }
            case 4:
                cout << (isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << "Stack size: " << getSize() << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
            }

            cout << endl;
            char choice;
            cout << "Do you want to continue (y/n)? ";
            cin >> choice;
            conti = (choice == 'y' || choice == 'Y');
        }

    } else if (k == 2) {
        int ch, val;
        bool conti = true;

        while (conti) {
            cout << "=======================================================" << endl;
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
                cout << (isEmptyQ() ? "Queue is empty." : "Queue is not empty.") << endl;
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
    } else {
        cout << "invalid exiting program" << endl;
    }

    return 0;
}