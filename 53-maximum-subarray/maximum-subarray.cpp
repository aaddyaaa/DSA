class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum = nums[0];
        int ans = nums[0];
        for (int  i = 1 ; i< nums.size(); i++){
            msum = max(msum+nums[i], nums[i]);
            ans = max(msum , ans) ;
        }
        return ans;
    }
};