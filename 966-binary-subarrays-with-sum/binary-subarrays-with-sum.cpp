class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int,int> prefixsumcount;
    int count = 0;
    int prefixsum = 0;
    prefixsumcount[0]=1;
    for (int i =0;i<nums.size();i++){
        prefixsum+= nums[i];

        if (prefixsumcount.find(prefixsum - goal)!=prefixsumcount.end()){
            count+=prefixsumcount[prefixsum - goal];
        }
        prefixsumcount[prefixsum]++;
    }
    return count;
    }
};