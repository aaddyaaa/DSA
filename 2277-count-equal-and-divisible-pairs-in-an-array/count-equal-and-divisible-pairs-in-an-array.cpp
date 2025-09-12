class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> groups;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        long long count = 0;

        for (auto &entry : groups) {
            vector<int>& idx = entry.second;
            int m = idx.size();

            for (int x = 0; x < m; x++) {
                for (int y = x + 1; y < m; y++) {
                    if ((1LL * idx[x] * idx[y]) % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
};