class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxr = 0;
        for (int i =0;i<n;i++){
            if (i>maxr){
                return false;
            }
            maxr= max(maxr,i+nums[i]);
            if (maxr==n-1) return true;
        }
        return true;
    }
};