#include <iostream> 
#include <climits> 
using namespace std; 
 
// A structure to store both min and max of an array 
struct MinMax { 
    int min; 
    int max; 
}; 
 
// Function to find min and max using divide and conquer 
MinMax findMinMax(int arr[], int low, int high) { 
    MinMax result, leftResult, rightResult; 
 
    // If the array contains only one element 
    if (low == high) { 
        result.min = result.max = arr[low]; 
        return result; 
    } 
 
    // If the array contains two elements 
    if (high == low + 1) { 
        if (arr[low] > arr[high]) { 
            result.max = arr[low]; 
            result.min = arr[high]; 
        } else { 
            result.max = arr[high]; 
            result.min = arr[low]; 
        } 
        return result; 
} 
// If the array contains more than two elements, divide the array 
int mid = (low + high) / 2; 
leftResult = findMinMax(arr, low, mid); 
rightResult = findMinMax(arr, mid + 1, high); 
// Compare the results of left and right subarrays 
result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min; 
result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max; 
return result; 
} 
int main() { 
int n; 
// Take the size of the array as input 
cout << "Enter the number of elements in the array: "; 
cin >> n; 
int arr[n]; 
// Take array elements as input 
cout << "Enter the elements of the array: "; 
for (int i = 0; i < n; i++) { 
cin >> arr[i]; 
} 
// Call the function to find min and max 
MinMax result = findMinMax(arr, 0, n - 1); 
// Output the result 
cout << "Minimum element: " << result.min << endl; 
cout << "Maximum element: " << result.max << endl; 
return 0; 
}