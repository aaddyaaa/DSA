class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int count = 0, l = 0, sum = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            sum += nums[r] % 2;

            while (sum > k) {
                sum -= nums[l] % 2;
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
