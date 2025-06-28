class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        string neew = "";
        for (int i=n-1;i>=0;i--){
            if (s[i]==' ' && neew!= ""){
                break;
            }
            else if (s[i]==' ' && neew==""){
                continue;
            }
            else {
                neew+=s[i];
            }
        }
        return neew.size();
    }
};