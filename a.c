#include <iostream>
using namespace std;

// Function to perform Quick Sort
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int partitionIndex = left;
        
        for (int i = left; i < right; i++) {
            if (arr[i] < pivot) {
                swap(arr[i], arr[partitionIndex]);
                partitionIndex++;
            }
        }
        swap(arr[partitionIndex], arr[right]);

        quickSort(arr, left, partitionIndex - 1);   // Sort the left subarray
        quickSort(arr, partitionIndex + 1, right);  // Sort the right subarray
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at the mid index
        if (arr[mid] == target) {
            return mid;
        }

        // If target is smaller than mid, search the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Else, search the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }
    
    // Target not found
    return -1;
}

int main() {
    int n;

    // Input the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input array elements (in any order)
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using Quick Sort
    quickSort(arr, 0, n - 1);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target, result;
    
    // Prompt until a valid target is entered and found
    while (true) {
        cout << "Enter the element to search for: ";
        cin >> target;

        // Perform binary search on the sorted array
        result = binarySearch(arr, 0, n - 1, target);

        if (result != -1) {
            cout << "Element found at index " << result << endl;
            break;
        } else {
            cout << "Element not found in the array. Please try again." << endl;
        }
    }

    return 0;
}
