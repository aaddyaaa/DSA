class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return getSum(nums, true) - getSum(nums, false);
    }

    long long getSum(vector<int>& nums, bool isMax) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<pair<int, int>> st;

        // Previous less/greater
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!st.empty() && (
                isMax ? st.top().first < nums[i] : st.top().first > nums[i])) {
                count += st.top().second;
                st.pop();
            }
            prev[i] = count;
            st.push({nums[i], count});
        }

        while (!st.empty()) st.pop();

        // Next less/greater
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!st.empty() && (
                isMax ? st.top().first <= nums[i] : st.top().first >= nums[i])) {
                count += st.top().second;
                st.pop();
            }
            next[i] = count;
            st.push({nums[i], count});
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += 1LL * nums[i] * prev[i] * next[i];
        }
        return sum;
    }
};
