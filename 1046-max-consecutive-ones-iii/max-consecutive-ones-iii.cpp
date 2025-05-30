class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0, l=0, zero =0, maxxx=0;
        int n = nums.size();
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            while(zero>k){
                if (nums[l]==0){
                    zero--;
                }
                l++;
            }
            maxxx = max(maxxx,r-l+1);
            r++;
        }
        return maxxx;
        
    }
};