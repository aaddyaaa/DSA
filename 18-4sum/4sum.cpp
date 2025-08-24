class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  // skip duplicate i
            
            for (int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;  // skip duplicate j
                
                long long newTarget = (long long)target - nums[i] - nums[j];
                int l = j+1, r = n-1;
                
                while (l < r) {
                    long long sum = nums[l] + nums[r];
                    if (sum < newTarget) {
                        l++;
                    } else if (sum > newTarget) {
                        r--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l-1]) l++;  // skip duplicate l
                        while (l < r && nums[r] == nums[r+1]) r--;  // skip duplicate r
                    }
                }
            }
        }
        return ans;


        
    }
};