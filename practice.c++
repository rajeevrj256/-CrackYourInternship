#include <iostream>
#include <vector>
using namespace std;

// Function to count swaps using bubble sort
int bubbleSortSwaps(vector<int>& arr, bool ascending) {
    int n = arr.size();
    int swapCount = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // If ascending is true, we want to sort in ascending order
            // If ascending is false, we want to sort in descending order
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                // Swap the elements
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
    }
    return swapCount;
}

// Main function to find the minimum swaps to make the array beautiful
int minSwapsToBeautiful(vector<int>& arr) {
    // Create copies of the original array
    vector<int> ascendingArr = arr;
    vector<int> descendingArr = arr;

    // Get swap counts for ascending and descending order
    int ascendingSwaps = bubbleSortSwaps(ascendingArr, true);
    int descendingSwaps = bubbleSortSwaps(descendingArr, false);

    // Return the minimum of the two swap counts
    return min(ascendingSwaps, descendingSwaps);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Output the minimum swaps to make the array beautiful
    cout << minSwapsToBeautiful(arr) << endl;

    return 0;
}
