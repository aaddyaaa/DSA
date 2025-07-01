class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while (r<n-1){
            int farthest = 0;
            for (int ind=l;ind<=r;ind++){
                farthest = max(ind + nums[ind], farthest);
            }
            l = r+1;
            r = farthest;
            jumps = jumps + 1;
        }
        return jumps;
    }
};