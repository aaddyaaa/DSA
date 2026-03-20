class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        if (nums.size()<= 2) return nums.size();
        ans.push_back(nums[0]);
        ans.push_back(nums[1]);
        for (int i = 2;i<nums.size();i++){
            int size = ans.size();
            if (nums[i]!=ans[size-2]) {
                ans.push_back(nums[i]);
            }
        }
        for(int i =0; i<ans.size();i++){
            nums[i]= ans[i];
        }
        return ans.size();
    }
};