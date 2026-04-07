class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> mp;
        unordered_map <char,char> mpp;
        for (int i = 0 ; i<s.size(); i++){
            if (mp.count(s[i]) && (mp[s[i]]!=t[i])) return false;
            mp[s[i]] = t[i];
            if (mpp.count(t[i]) && (mpp[t[i]]!=s[i])) return false;
            mpp[t[i]] = s[i];
        }
        return true;
    }
};