class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
    unordered_set<int> s(nums.begin(), nums.end()); 
    int totalDistinct = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> freq;
        int distinctCount = 0;
        for (int j = i; j < n; j++) {
            if (freq[nums[j]] == 0) distinctCount++;
            freq[nums[j]]++;
            if (distinctCount == totalDistinct) ans++;
        }
    }
    return ans;
        
    }
};