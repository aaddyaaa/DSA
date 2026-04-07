class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for (char c : ransomNote){
            freq[c]++;
        }
        unordered_map<char, int> freq1;
        for (char c : magazine){
            freq1[c]++;
        }
        bool isvalid = true;
        for (auto it : freq){
            char f = it.first;
            int n = it.second;
            if(freq1[f]<n){
                isvalid = false;
                break;
            }
        }
        return isvalid;
    }
};