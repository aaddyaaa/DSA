class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int maxx = 0;
        for (int i = 0;i<n ; i++){
             if (nums[i] == 1) {
                cnt++;
                maxx = max(maxx, cnt);
            } else {
                cnt = 0;
            }
        }
        return maxx;
    }
};