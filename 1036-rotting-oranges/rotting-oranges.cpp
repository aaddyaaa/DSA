class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int, int>, int>> q;  // {{row, col}, time}
        int fresh = 0;

        // Direction vectors for 4-directional movement
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        // Initialize the queue with all initially rotten oranges
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({{r, c}, 0});
                } else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int maxTime = 0;

        // BFS
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            int time = front.second;

            maxTime = max(maxTime, time);

            // Check all 4 adjacent cells
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                // Valid and fresh
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // Mark as rotten
                    q.push({{nr, nc}, time + 1});
                    fresh--;
                }
            }
        }

        return (fresh == 0) ? maxTime : -1;
        
    }
};