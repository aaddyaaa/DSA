class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int sum = 0;
        int max_s = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        for (r=0 ;r<n ;r++){
            while(seen.count(nums[r])){
                seen.erase(nums[l]);
                sum-= nums[l];
                l++;
            }
            sum+= nums[r];
            seen.insert(nums[r]);
            max_s = max(sum,max_s);
        }
        return max_s;

    }
};