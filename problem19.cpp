#include<bits/stdc++.h>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void displayArray(float arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void heapify(int arr[], int index, int n) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, n);
    }
}
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, 0, i);
    }
}
void countSort(int arr[], int n) {
    int maximumElement = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maximumElement) {
            maximumElement = arr[i];
        }
    }
    int count[maximumElement + 1] = {0}; // Initializing count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++; // Counting  each element
    }
    for (int i = 1; i < maximumElement + 1; i++) {
        count[i] += count[i - 1]; // Build the cumulative count array
    }
    // Place elements in the sorted array using the cumulative count
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i]; //put after decrementing
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];    // Copy to original array
    }
}
void radixSort(int arr[], int n) {
    int maximunElement = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maximunElement) {
            maximunElement = arr[i];
        }
    }
    //count sort based on digit
    for (int div = 1; maximunElement / div > 0; div = div * 10) {
        int output[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            count[(arr[i] / div) % 10]++; //incresing count array based on div
        }
        for (int i = 1; i < 10; i++) { 
            count[i] += count[i - 1];   //cummulative count array
        }
        for (int i = n - 1; i >= 0; i--) {
            output[--count[(arr[i] / div) % 10]] = arr[i];
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}
void bucketSort(float arr[], int n) {
    float maxElement = -9999999999.0;
    float minElement = 9999999999.0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxElement) maxElement = arr[i];
        if (arr[i] < minElement) minElement = arr[i];
    }

    float bucketList[n][n];
    int bucketSizes[n]={0};

    // Calculate range for each bucket
    float range = (maxElement - minElement) / (n);
    if (range == 0) range = 1; // Ensure that range is at least 1

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minElement) / range; // Determine the bucket index
        if (bucketIndex == n) bucketIndex--; // Ensure it's within bounds
        bucketList[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            bubbleSort(bucketList[i], bucketSizes[i]); // Sort the bucket using bubblesort
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = bucketList[i][j]; // Place the sorted elements back into the original array
            }
        }
    }
}

int main() {
    int n, choice;
    cout << "Select Sorting Algorithm:" << endl;
    cout << "1. Heap Sort" << endl;
    cout << "2. Count Sort " << endl;
    cout << "3. Radix Sort " << endl;
    cout << "4. Bucket Sort " << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 5) {
        cout << "Exiting..." << endl;
        return 0;
    }
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Array size must be positive. Setting it to 5." << endl;
        n = 5;
    }
    if (choice == 4) {
        float arr[n];
        cout << "Enter the element of the array (float): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Before Sorting (Bucket Sort): " << endl;
        displayArray(arr, n);
        bucketSort(arr, n);
        cout << "After Sorting (Bucket Sort): " << endl;
        displayArray(arr, n);
    } else {
        int arr[n];
        cout << "Enter the element of the array (int): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        switch (choice) {
            case 1:
                cout << "Before Sorting (Heap Sort): " << endl;
                displayArray(arr, n);
                buildMaxHeap(arr, n);
                cout << "Max heap: " << endl;
                displayArray(arr, n);
                heapSort(arr, n);
                cout << "After Sorting (Heap Sort): " << endl;
                displayArray(arr, n);
                break;
            case 2:
                cout << "Before Sorting (Count Sort): " << endl;
                displayArray(arr, n);
                countSort(arr, n);
                cout << "After Sorting (Count Sort): " << endl;
                displayArray(arr, n);
                break;
            case 3:
                cout << "Before Sorting (Radix Sort): " << endl;
                displayArray(arr, n);
                radixSort(arr, n);
                cout << "After Sorting (Radix Sort): " << endl;
                displayArray(arr, n);
                break;
            default:
                cout << "Invalid choice!" << endl;
                cout << "Exiting..." << endl;
                return 0;
        }
    }
    return 0;
}