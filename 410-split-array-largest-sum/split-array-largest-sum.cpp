class Solution {
public:
bool isPossible(vector<int>& nums, int k, int maxSum) {
    int parts = 1;
    int currSum = 0;

    for (int num : nums) {
        if (num > maxSum) return false;

        if (currSum + num > maxSum) {
            parts++;
            currSum = num;
        } else {
            currSum += num;
        }
    }

    return parts <= k;
}

    int splitArray(vector<int>& nums, int k) {    
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
        
    }
};