class Solution {
public:
    int maxProduct(vector<int>& arr) { // Renamed from maxProductSubArray to maxProduct
        int n = arr.size(); // Size of the array
        
        int pre = 1, suff = 1; // Prefix and Suffix product
        int ans = INT_MIN; // To store the maximum product
        
        for (int i = 0; i < n; i++) {
            // Reset prefix and suffix product if they become zero
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;

            // Calculate prefix product (left to right)
            pre *= arr[i];
            // Calculate suffix product (right to left)
            suff *= arr[n - i - 1];

            // Update the maximum product
            ans = max(ans, max(pre, suff));
        }

        return ans; // Return the maximum product found
    }
};
