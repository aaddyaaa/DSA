class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0 ; i< n ; i++){
            if(i>pos)return false; // the pos is where we can reach max but if we're at i we cant reach then return false;
            pos = max(pos,i+nums[i]);
        }
        return true;
    }
};