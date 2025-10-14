class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        vector<vector<int>> apples(rows + 1, vector<int>(cols + 1, 0));

        for (int r = rows - 1; r >= 0; --r) {
            for (int c = cols - 1; c >= 0; --c) {
                apples[r][c] = (pizza[r][c] == 'A') 
                    + apples[r+1][c] + apples[r][c+1] - apples[r+1][c+1];
            }
        }

        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k+1, -1)));

        function<int(int,int,int)> dfs = [&](int r, int c, int cuts_left) -> int {
            if (apples[r][c] == 0) return 0;   
            if (cuts_left == 1) return 1;     

            if (dp[r][c][cuts_left] != -1) return dp[r][c][cuts_left];
            long long ways = 0;

            for (int nr = r + 1; nr < rows; ++nr) {
                if (apples[r][c] - apples[nr][c] > 0)
                    ways = (ways + dfs(nr, c, cuts_left - 1)) % MOD;
            }

            for (int nc = c + 1; nc < cols; ++nc) {
                if (apples[r][c] - apples[r][nc] > 0)
                    ways = (ways + dfs(r, nc, cuts_left - 1)) % MOD;
            }

            return dp[r][c][cuts_left] = ways;
        };

        return dfs(0, 0, k);
    }
};