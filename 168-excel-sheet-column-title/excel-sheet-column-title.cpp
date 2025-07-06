class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  // Adjust because A = 1, not 0
            int rem = columnNumber % 26;
            result = char('A' + rem) + result;
            columnNumber /= 26;
        }
        return result;
    }
};
