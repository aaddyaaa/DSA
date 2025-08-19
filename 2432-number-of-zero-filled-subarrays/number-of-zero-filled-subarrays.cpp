class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    long long count = 0;
    long long zeroStreak = 0;

    for (int num : nums) {
        if (num == 0) {
            zeroStreak++;        
            count += zeroStreak; 
        } else {
            zeroStreak = 0;      
        }
    }
    return count;
    }
};