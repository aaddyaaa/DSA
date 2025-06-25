class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto &num:nums){
            map[num]++;
        }
        vector<pair<int,int>> v;
        for(auto &n:map){
            v.push_back({n.second,n.first});
        }
        sort(v.rbegin(),v.rend());
        vector<int> res;
        for(int i = 0;i < k;i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};