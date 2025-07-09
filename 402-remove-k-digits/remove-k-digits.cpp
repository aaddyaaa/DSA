class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }
        string result = "";
        bool leadingZero = true;
        for (char digit : stack) {
            if (leadingZero && digit == '0') continue;
            leadingZero = false;
            result += digit;
        }

        return result.empty() ? "0" : result;
        
    }
};