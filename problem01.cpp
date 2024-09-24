#include <iostream>
using namespace std;

void traverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertAtBeginning(int arr[], int &n, int value, int capacity)
{
    if (n >= capacity)
    {
        cout << "Array is full." << endl;
        return;
    }
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = value;
    n++;
    cout << "Value " << value << " is inserted at the beginning of the array." << endl;
    cout << "Your updated array is: " << endl;
    traverse(arr, n);
}

void insertAtEnd(int arr[], int &n, int value, int capacity)
{
    if (n >= capacity)
    {
        cout << "Array is full." << endl;
        return;
    }
    arr[n] = value;
    n++;
    cout << "Value " << value << " is inserted at the end of the array." << endl;
    cout << "Your updated array is: " << endl;
    traverse(arr, n);
}

void insertAtPosition(int arr[], int &n, int value, int position, int capacity)
{
    if (position < 0 || position > n)
    {
        cout << "Invalid position." << endl;
        return;
    }
    if (n >= capacity)
    {
        cout << "Array is full." << endl;
        return;
    }
    for (int i = n; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = value;
    n++;
    cout << "Value " << value << " is inserted at position " << position << "." << endl;
    cout << "Your updated array is: " << endl;
    traverse(arr, n);
}

void deleteFromBeginning(int arr[], int &n)
{
    if (n <= 0)
    {
        cout << "Array is empty." << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    cout << "Element deleted from the beginning of the array." << endl;
    cout << "Your updated array is: " << endl;
    traverse(arr, n);
}

void deleteFromEnd(int arr[], int &n)
{
    if (n <= 0)
    {
        cout << "Array is empty." << endl;
        return;
    }
    n--;
    cout << "Element deleted from the end of the array." << endl;
    cout << "Your updated array is: " << endl;
    traverse(arr, n);
}

void deleteFromPosition(int arr[], int &n, int position)
{
    if (position < 0 || position >= n)
    {
        cout << "Invalid position." << endl;
        return;
    }
    for (int i = position; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    cout << "Element deleted from position " << position << "." << endl;
    cout << "Your updated array is: " << endl;
    traverse(arr, n);
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
     int capacity = 100; // Set the maximum capacity of the array
    int arr[capacity];
    int n = 0; // Initialize the size of the array to 0

    cout << "Enter the number of elements in your array (max: " << capacity << "): ";
    int numElements;
    cin >> numElements;

    if (numElements > capacity) {
        cout << "Number of elements exceeds capacity. Setting size to " << capacity << "." << endl;
        cout << "as you have given larger than capacity we are taking number of elemts as 5 by default" << endl;
        numElements = 5;
    }

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < numElements; i++) {
        cin >> arr[i];
    }
    n = numElements; // Update the size of the array

    bool continueProgram = true;

    while (continueProgram)
    {
        cout << "\nMenu:\n";
        cout << "1. Traverse Array\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete from Position\n";
        cout << "8. Linear Search\n";
        cout << "9. Binary Search (Array should be sorted)\n";
        cout << "10. Insertion Sort\n";
        cout << "Enter your choice: ";
        int choice, value, position;
        cin >> choice;

        switch (choice)
        {
        case 1:
            traverse(arr, n);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtBeginning(arr, n, value, capacity);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtEnd(arr, n, value, capacity);
            break;
        case 4:
            cout << "Enter value to insert : ";
            cin >> value;
            cout << "Enter position to insert (0-based index) from 0 to "<<n<<" : ";
            cin >> position;
            insertAtPosition(arr, n, value, position, capacity);
            break;
        case 5:
            deleteFromBeginning(arr, n);
            break;
        case 6:
            deleteFromEnd(arr, n);
            break;
        case 7:
            cout << "Enter position to delete (0-based index) 0 to "<<n-1<<": ";
            cin >> position;
            deleteFromPosition(arr, n, position);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            position = linearSearch(arr, n, value);
            if (position != -1)
                cout << "Element found at position: " << position << endl;
            else
                cout << "Element not found." << endl;
            break;
        case 9:
            cout << "Enter value to search: ";
            cin >> value;
            position = binarySearch(arr, 0, n - 1, value);
            if (position != -1)
                cout << "Element found at position : " << position << endl;
            else
                cout << "Element not found." << endl;
            break;
        case 10:
            insertionSort(arr, n);
            cout << "Array sorted successfully." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

        // Ask if the user wants to continue
        char cont;
        cout << "\nDo you want to continue? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
        {
            continueProgram = false;
            cout << "Exiting program." << endl;
        }
    }

return 0;
}