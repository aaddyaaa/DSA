class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        for (int num:s){
            if(!s.count(num-1)){
                int currentnum = num;
                int streak = 1;
                while (s.count(currentnum+1)){
                    currentnum++;
                    streak++;
                }
                longest = max(longest,streak);
            }
        }
    

        return longest;
    }
};