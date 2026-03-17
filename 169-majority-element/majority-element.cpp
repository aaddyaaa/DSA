class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int y = (n/2);
        unordered_map <int,int> freq;
        for (int x : nums){
            freq[x]++;
            if (freq[x]> y) return x;
        }
        return -1;
    }
};