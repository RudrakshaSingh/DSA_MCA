#include <iostream>
using namespace std;

int queue[100];
int maxSize, front, rear;

void createQueue()
{
    cout << "Enter the size of the Queue (max 100): ";
    cin >> maxSize;
    if (maxSize > 100 || maxSize <= 0)
    {
        cout << "Invalid size. Setting queue size to 100." << endl;
        maxSize = 100;
    }
    front = rear = -1;
}

void Enqueue(int val)
{
    if (rear >= maxSize - 1) // Check for queue overflow
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        if (front == -1) // First element being added
        {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        cout << val << " added to queue." << endl;
    }
}

void Dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        cout << "Dequeued element is " << queue[front] << endl;
        front++;

        // Reset queue if it becomes empty
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

int getFront()
{
    if (front == -1)
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    else
    {
        return queue[front];
    }
}

bool isEmpty()
{
    return (front == -1); // Queue is empty if front is -1
}

bool isFull()
{
    return (rear >= maxSize - 1); // Queue is full
}

int CurrentSize()
{
    if (front == -1) return 0; // If queue is empty, size is 0
    return rear - front + 1; // Calculate current size
}

int main()
{
    int ch, val;
    cout << "Creating Queue :" << endl;
    createQueue();
    cout << "QUEUE CREATED" << endl;
    cout << endl;

    bool conti = true;
    while (conti)
    {
        cout << "=================================================================================" << endl;

        cout << "(1) Enqueue in Queue             ";
        cout << "(2) Dequeue from Queue           ";
        cout << "(3) Peek at front element        " << endl;
        cout << "(4) Check if Queue is empty      ";
        cout << "(5) Check if Queue is full       ";
        cout << "(6) Get queue size               " << endl;

        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
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

    return 0;
}
