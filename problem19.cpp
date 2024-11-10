#include<bits/stdc++.h>
using namespace std;

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int index, int n ){
    int largest = index;
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;

    if (leftChild < n && arr[leftChild]>arr[largest])
    {
        largest=leftChild;
    }
    if (rightChild < n && arr[rightChild]>arr[largest])
    {
        largest=rightChild;
    }

    if (largest!=index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapify(arr,largest,n);
    }
}

void buildMaxHeap(int arr[], int n){
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr,i,n);
    }  
}

void heapSort(int arr[], int n){
    for (int i = n-1; i > 0; i--)
    {
        int temp = arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapify(arr,0,i);
    }
}

void countSort(int arr[], int n) {
    // Finding the maximum element
    int maximunElement = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maximunElement) {
            maximunElement = arr[i];
        }
    }
    
    // Initializing count array
    int *count = (int *)malloc((maximunElement + 1) * sizeof(int));
    for (int i = 0; i < maximunElement + 1; i++) {
        count[i] = 0;
    }

    // Counting  each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Build the cumulative count array
    for (int i = 1; i < maximunElement + 1; i++) {
        count[i] += count[i - 1];
    }

    // Place elements in the sorted array using the cumulative count
    int *output = (int *)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

void radixSort(int arr[], int n){
    //finding maximum element
    int maximunElement = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>maximunElement)
        {
            maximunElement=arr[i];
        }
    }
    //count sort based on digit
    for (int div = 1; maximunElement/div>0; div=div*10)
    {
        int *output=(int *)malloc(n*sizeof(int));
        int count[10] = {0};

        
        for (int i = 0; i < n; i++)
        {
            count[(arr[i]/div)%10]++;//incresing count array based on units place then tenth place etc
        }
        
        for (int i = 1; i < 10; i++) {//cummulative count array
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / div) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        free(output);
    }
}

int main() {
    int n, choice;

    cout << "Enter the number of elements : ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.Setting it to 5." << endl;
        n=5;
    }

    int* arr=(int*)malloc(n * sizeof(int));

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Select Sorting Algorithm:" << endl;
    cout << "1. Heap Sort" << endl;
    cout << "2. Count Sort " << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Before Sorting (Heap Sort): " << endl;
        displayArray(arr, n);

        buildMaxHeap(arr,n);
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
        cout << "Before Sorting (radix Sort): " << endl;
        displayArray(arr, n);
        radixSort(arr, n);
        cout << "After Sorting (Count Sort): " << endl;
        displayArray(arr, n);
    case 5:
        cout << "Exiting..." << endl;
        return 0;

    default:
        cout << "Invalid choice!" << endl;
        cout << "Exiting..." << endl;
        return 0;
    }
    return 0;
}
