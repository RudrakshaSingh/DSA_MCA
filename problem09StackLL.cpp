#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

int getSize() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count; 
}

void push(int val) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout << val << " pushed to stack." << endl;
}

void pop() {
    if (head == nullptr) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "The popped element is " << head->data << endl;
    Node* temp = head;
    head = head->next;
    free(temp); 
}

int peek() {
    if (head == nullptr) {
        cout << "Stack is empty." << endl;
        return -1; 
    }
    return head->data;
}

bool isEmpty() {
    return head == nullptr;
}

int main() {
    int ch, val;
    cout << "STACK CREATED" << endl;
    cout << endl;

    bool conti = true;
    while (conti) {
        cout << "=================================================================================" << endl;

        cout << "(1) Push in stack             ";
        cout << "(2) Pop from stack             ";
        cout << "(3) Peek at top element" << endl;
        cout << "(4) Check if stack is empty   ";
        cout << "(5) Get stack size"<<endl;

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
        }

        cout << endl;
        char choice;
        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
        conti = (choice == 'y' || choice == 'Y');
    }

    // Clean up remaining nodes
    while (!isEmpty()) {
        pop();
    }

    return 0;
}
