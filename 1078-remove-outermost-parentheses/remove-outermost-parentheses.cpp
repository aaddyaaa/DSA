class Solution {
public:
    string removeOuterParentheses(string s) {
        int start = 0;
        int balance = 0;
        int n = s.size();
        string result;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                balance++;
            }
            if(s[i]==')'){
                balance--;
            }
            if(balance == 0){
                //skip outermost parantheses
                result+=s.substr(start+1,i-start-1);
                // i-start-1 means include this no of chars also remove outermost parantheses
                start = i+1;
            }
        }
        return result;
    }
};