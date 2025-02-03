class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n-1;
        int low = 0;

        while(low<= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                //search space shrink
                low= low+1;
                high = high-1;
                continue;

            }
            if(nums[low] <= nums[mid]){               //left part is sorted
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
               
            }
            //right sorted array
            else{
                if (nums[mid] <= target && target <= nums[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }


            }

        }
        return false;
        
    }
};