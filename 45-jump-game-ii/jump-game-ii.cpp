class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int farthest = 0;
        int jumps = 0;
        int n = nums.size();
        while (r<n-1){
            for (int i = l ;i<=r ;i++){
                farthest = max(i+nums[i], farthest);
            }
            l=r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};