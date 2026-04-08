class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string, vector<string>> mpp;
        for (string s : strs){
            string key = s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }
        for (auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};