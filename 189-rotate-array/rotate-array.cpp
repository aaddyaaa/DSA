class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k= k%n; // in case shift by 11 but n = 7 only so whole will shift by 4 only which is remainder of 11/7
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }
};