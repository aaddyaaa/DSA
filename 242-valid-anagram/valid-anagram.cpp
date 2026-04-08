class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> mp;
        for (char c : s){
            mp[c]++;
        }
        unordered_map <char,int> mpp;
        for (char c : t){
            mpp[c]++;
        }
        if (mp == mpp) return true;
        else return false;
    }
};