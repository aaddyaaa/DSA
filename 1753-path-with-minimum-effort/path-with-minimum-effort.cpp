class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pq.emplace(0, 0, 0);  
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            if (r == rows - 1 && c == cols - 1)
                return effort;

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int next_effort = max(effort, abs(heights[nr][nc] - heights[r][c]));
                    if (next_effort < dist[nr][nc]) {
                        dist[nr][nc] = next_effort;
                        pq.emplace(next_effort, nr, nc);
                    }
                }
            }
        }
        return 0;
        
    }
};