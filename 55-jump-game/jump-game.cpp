class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_ind = 0;
        for (int i =0; i<n ;i++){
            if (i>max_ind) return false;
            max_ind = max(max_ind, i+nums[i]);
            if (max_ind>=n-1) return true;
        }
        return true;
    }
};