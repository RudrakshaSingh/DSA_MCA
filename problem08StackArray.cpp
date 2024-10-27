#include <iostream>

using namespace std;

int stack[100];
int n = 0, top = -1;

void createStack() {
    cout << "Enter the size of the stack (max 100): ";
    cin >> n;
    if (n > 100 || n <= 0) {
        cout << "Invalid size. Setting stack size to 100." << endl;
        n = 100;
    }
    top = -1;
}

void push(int val) {
    if (top >= n - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        top++;
        stack[top] = val;
        cout << val << " pushed to stack." << endl;
    }
}

void pop() {
    if (top <= -1) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

int peek() {
    if (top <= -1) {
        cout << "Stack is empty." << endl;
        return -1; // Indicate empty stack
    } else {
        return stack[top];
    }
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top >= n - 1);
}

int size() {
    return top + 1; // Size is top index + 1
}

int main() {
    int ch, val;
    cout << "Creating Stack :" << endl;
    createStack();
    cout << "STACK CREATED" << endl;
    cout << endl;

    bool conti = true;
    while (conti) {
        cout << "=================================================================================" << endl;

        cout << "(1) Push in stack             ";
        cout << "(2) Pop from stack             ";
        cout << "(3) Peek at top element" << endl;
        cout << "(4) Check if stack is empty   ";
        cout << "(5) Check if stack is full     ";
        cout << "(6) Get stack size       " << endl;

        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "Enter value to be pushed [0-9]:";
            cin >> val;
            push(val);
            break;
        }
        case 2: {
            pop();
            break;
        }
        case 3: {
            int topElement = peek();
            if (topElement != -1) {
                cout << "Top element is: " << topElement << endl;
            }
            break;
        }
        case 4: {
            cout << (isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        }
        case 5: {
            cout << (isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        }
        case 6: {
            cout << "Stack size: " << size() << endl;
            break;
        }
        default: {
            cout << "Invalid Choice" << endl;
        }
        }

        cout << endl;
        char choice;
        cout << "Do you want to continue (y/n)?" << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            conti = true;
        } else {
            conti = false;
        }
    }

    return 0;
}