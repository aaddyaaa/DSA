class Solution {
public:
    bool isPalindrome(int x) {
        long long result = 0;
        if (x<0) return false;
        int original = x;
        while (x!=0){
            int digit = x% 10 ;
            x = x/10;
            result = result * 10 + digit;
        }
        if (result == original) return true;
        else return false;
    }
};