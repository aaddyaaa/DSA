class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vectorr;
        unordered_map <int , int> mapp;
        for (int num : nums) {
            mapp[num]++;
        }
        vector<pair<int, int>> freqVec;
        for (auto& entry : mapp) {
            freqVec.push_back({entry.first, entry.second});
        }
        
        sort(freqVec.begin(),freqVec.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second > b.second;});
        for (int x = 0; x < k; x++) {
            vectorr.push_back(freqVec[x].first);
        }
        return vectorr;
    }
};