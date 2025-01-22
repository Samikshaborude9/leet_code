class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0; // Counters for the two potential majority elements
        int el1 = INT_MIN, el2 = INT_MIN; // Candidates for the majority elements
        int n = nums.size();
        
        // First pass: Find the two candidates using the Boyer-Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Second pass: Verify if the candidates appear more than ⌊n/3⌋ times
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
        }
        
        // Threshold for majority elements
        int mini = n / 3;
        vector<int> result;
        if (cnt1 > mini) result.push_back(el1);
        if (cnt2 > mini) result.push_back(el2);
        
        return result;
    }
};
