class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++) {
        long long anss = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1; col < i; col++) {
            anss = anss * (i - col);
            anss = anss / col;
            ansRow.push_back(anss);
        }
        ans.push_back(ansRow);    
    }
    return ans;
    }
};