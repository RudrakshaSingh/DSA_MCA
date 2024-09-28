#include <iostream>
using namespace std;

int stack[100];      // Static array with a maximum size
int n = 0, top = -1; // Stack size and top index

void createStack()
{
    cout << "Enter the size of the stack (max 100): ";
    cin >> n;
    if (n > 100 || n <= 0)
    {
        cout << "Invalid size. Setting stack size to 100." << endl;
        n = 100;
    }
    top = -1; // Reset top for the new stack
}

void push(int val)
{
    if (top >= n - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = val;
        cout << val << " pushed to stack." << endl;
    }
}

void pop()
{
    if (top <= -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

int peek()
{
    if (top <= -1)
    {
        cout << "Stack is empty." << endl;
        return -1; // Indicate empty stack
    }
    else
    {
        return stack[top];
    }
}

bool isEmpty()
{
    return (top == -1);
}

bool isFull()
{
    return (top >= n - 1);
}

int size()
{
    return top + 1; // Size is top index + 1
}

int main()
{
    int ch, val;
    cout << "Creating Stack :" << endl;
    createStack();
    cout << "STACK CREATED" << endl;
    cout << endl;

    do
    {
        cout << "=================================================================================" << endl;

        cout << "(1) Create Stack         ";
        cout << "(2) Push in stack             ";
        cout << "(3) Pop from stack" << endl;
        cout << "(4) Peek at top element  ";
        cout << "(5) Check if stack is empty   ";
        cout << "(6) Check if stack is full" << endl;
        cout << "(7) Get stack size       ";
        cout << "(8) Exit" << endl;

        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            createStack();
            break;
        }
        case 2:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 3:
        {
            pop();
            break;
        }
        case 4:
        {
            int topElement = peek();
            if (topElement != -1)
            {
                cout << "Top element is: " << topElement << endl;
            }
            break;
        }
        case 5:
        {
            cout << (isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        }
        case 6:
        {
            cout << (isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        }
        case 7:
        {
            cout << "Stack size: " << size() << endl;
            break;
        }
        case 8:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 8);

    return 0;
}
