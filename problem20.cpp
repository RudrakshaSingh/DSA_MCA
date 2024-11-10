#include <iostream>
using namespace std;


// Merge Sort Helper Functions
void merge(int arr[], int low, int mid, int high) {
    int temp[high - low + 1]; // temporary array
    int left = low;           // starting index of left half of arr
    int right = mid + 1;      // starting index of right half of arr
    int k = 0;                // index for temp array

    // Storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k] = arr[left];
            left++;  
            k++;     
        } else {
            temp[k++] = arr[right++];
        }
    }

    // If elements on the left half are still remaining
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // If elements on the right half are still remaining
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // temporary array to the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    free(temp); 
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}

// Function for Quick Sort 
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low; 
    int j = high;

    // Use a for loop to iterate from low + 1 to high
    for (int k = low + 1; k <= high; k++) {
        if (arr[k] < pivot) {
            i++;  // Increment i for elements smaller than pivot
            // Swap arr[i] and arr[k]
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }

    // Swap pivot with arr[i] to place the pivot in the correct position
    //i will point to the last element smaller than the pivot.
    int temp = arr[low];
    arr[low] = arr[i];
    arr[i] = temp;

    return i; // Return the pivot's final position
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partionIndex = partition(arr, low, high); // put pivot in correct place and return index
        quickSort(arr, low, partionIndex - 1);        // left partition
        quickSort(arr, partionIndex + 1, high);       // right partition
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, choice;

    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];


    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Select Sorting Algorithm:" << endl;
    cout << "1. Merge Sort" << endl;
    cout << "2. Quick Sort " << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Before Sorting (Merge Sort): " << endl;
        displayArray(arr, n);
        mergeSort(arr, 0, n - 1);
        cout << "After Sorting (Merge Sort): " << endl;
        displayArray(arr, n);
        break;

    case 2:
        cout << "Before Sorting (Quick Sort): " << endl;
        displayArray(arr, n);
        quickSort(arr, 0, n - 1);
        cout << "After Sorting (Quick Sort): " << endl;
        displayArray(arr, n);
        break;

    case 3:
        cout << "Exiting..." << endl;
        return 0;

    default:
        cout << "Invalid choice!" << endl;
        cout << "Exiting..." << endl;
        return 0;
    }
    return 0;
}
