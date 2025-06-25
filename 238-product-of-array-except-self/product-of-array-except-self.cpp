class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int totalProduct = 1;
        int zeroCount = 0;
        for (int num : nums) {
            if (num != 0) {
                totalProduct *= num;
            } else {
                zeroCount++;
            }
        }
        vector<int> ans(n, 0);  
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1) {
                ans[i] = 0;  
            } else if (zeroCount == 1) {
                
                if (nums[i] == 0) {
                    ans[i] = totalProduct;
                }
            } else {
                ans[i] = totalProduct / nums[i];
            }
        }
        return ans;
        
    }
};