class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string result = "";
        int i = n-1;
        while (i>=0){
            while (i>=0 && s[i]==' ') {
                i-- ;
            }
            if (i<0) break;
            string word = "";
            while (i>=0 && s[i]!=' '){
                word = s[i]+word;
                i--;
            }
            if (result!="") {
            result += " ";
            }
            result+= word;
        }
        return result; 
    }
};