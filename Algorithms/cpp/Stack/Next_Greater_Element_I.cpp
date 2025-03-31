class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        
        for (int num : nums1) {
            int nextGreater = -1;
            bool found = false;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == num) {
                    found = true;
                }
                if (found && nums2[j] > num) { 
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
        
    }
};
