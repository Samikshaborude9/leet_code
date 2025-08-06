class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};               // handle empty input

        vector<int> result(n, -1);           // default -1 if no next greater
        stack<int> st;                       // store indices, monotonic decreasing by value

        for (int i = 0; i < 2 * n; i++) {    // full for loop, simulate circular array
            int idx = i % n;
            int current = nums[idx];

            // pop smaller elements and set their next greater to current
            while (!st.empty() && nums[st.top()] < current) {
                result[st.top()] = current;
                st.pop();
            }

            // only push indices during the first pass so each index is pushed once
            if (i < n) {
                st.push(idx);
            }
        }

        return result;
    }
};
