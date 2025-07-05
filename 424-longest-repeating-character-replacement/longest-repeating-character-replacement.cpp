class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0;
        int r=0;
        int hash[26]= {0};
        int max_len = 0;
        int max_freq = 0;
        while(r<n){
            hash[s[r]-'A']++;
            max_freq = max(max_freq,hash[s[r]-'A']);
            while ((r - l + 1) - max_freq > k) {
            hash[s[l] - 'A']--;
            l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
        
    }
};