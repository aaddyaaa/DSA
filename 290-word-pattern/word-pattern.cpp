class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, string> ps;
        unordered_map <string , char> sp;
        stringstream ss (s);
        string word;
        vector<string> words;
        while (ss >>  word){
            words.push_back(word);
        }
        if (pattern.size() != words.size()) return false;
        int n = words.size();
        for (int i = 0 ; i < n ; i++){
            if (ps.count(pattern[i]) && ps[pattern[i]]!=words[i]) return false;
            if (sp.count(words[i]) && sp[words[i]]!=pattern[i]) return false;
            ps[pattern[i]]=words[i];
            sp[words[i]]=pattern[i];
        }
        return true;
    }
};