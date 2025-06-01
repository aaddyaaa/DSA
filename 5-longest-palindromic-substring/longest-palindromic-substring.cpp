class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int low,high;
        int st=0 ; 
        int len=1;
        for(int i=1;i<n;i++){
            low = i-1;
            high = i;
            while(low>=0 && high<n && s[low]==s[high]){
                
                if(high-low+1 > len){
                    st = low;
                    len = high-low+1;
                }
                low--;high++;
            }
            low = i-1;
            high = i+1;
            while(low >=0 && high<n && s[low]==s[high]){
                
                if(high-low+1 > len){
                    st = low;
                    len = high-low+1;
                }
                low--;high++;
            }  
        }
        return s.substr(st,len);
    }
};