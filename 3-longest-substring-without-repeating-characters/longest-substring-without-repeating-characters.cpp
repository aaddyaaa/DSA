class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        vector<int> hash(256, -1);
        int max_len = 0;

        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len = r-l+1;
            max_len = max(max_len,len);
            hash[s[r]]=r; //stores index
            r++;

        }
        return max_len;
    }
};