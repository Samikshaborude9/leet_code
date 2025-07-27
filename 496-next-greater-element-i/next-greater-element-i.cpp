class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        stack<int> st;

        for(int i=0; i<nums2.size(); i++){
            int num = nums2[i];

            while(!st.empty() && num > st.top()){
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        //if no next num exist, then retun -1

        for(int i=0; i<nums1.size(); i++){
            if(nge.find(nums1[i]) != nge.end()){
                nums1[i] = nge[nums1[i]];
            } else{
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};