class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> freq;

        for (int x = 1; x <= n; x++) {
            int sum = 0, temp = x;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            freq[sum]++;
        }

        int maxCount = 0;
        for (auto &p : freq) {
            maxCount = max(maxCount, p.second);
        }

        int ans = 0;
        for (auto &p : freq) {
            if (p.second == maxCount) ans++;
        }

        return ans;
    }
};