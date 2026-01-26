class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    unordered_map<int,int> seen;
    int n = nums.size();
    int b = n/2;
    for (int x : nums) {
        seen[x]++;
        if ((seen[x])==b) {
            return x;
        }
    }
    return-1;
        
    }
};