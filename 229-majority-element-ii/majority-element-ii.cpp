class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> returnn;
        map <int,int> mpp;
        for(int i=0; i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for (auto it : mpp){
            if (it.second >(nums.size()/3)){
                returnn.push_back(it.first);
            }
        }
        return returnn;
        
    }
};