class Solution {
public:
    // Function to merge two sorted halves and count reverse pairs
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp; // Temporary array to store sorted elements
        int left = low;   // Starting index of the left half
        int right = mid + 1; // Starting index of the right half

        // Merge the two halves into the temp array in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Append remaining elements of the left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Append remaining elements of the right half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy back the sorted elements into the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Function to count reverse pairs
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    // Merge Sort function to count reverse pairs
    int mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0; // Base case: single element or invalid range

        int mid = (low + high) / 2;
        int cnt = 0;

        cnt += mergeSort(arr, low, mid);        // Count in left half
        cnt += mergeSort(arr, mid + 1, high);  // Count in right half
        cnt += countPairs(arr, low, mid, high); // Count reverse pairs
        merge(arr, low, mid, high);            // Merge the two halves

        return cnt;
    }

    int reversePairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1); // Call the merge sort helper
    }
};
