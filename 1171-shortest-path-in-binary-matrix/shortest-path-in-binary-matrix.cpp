class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        q.push({1,{0,0}});
        vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };
        while(!q.empty()){
            auto [d, cell] = q.front(); q.pop();
            int x = cell.first, y = cell.second;
            if (x == n-1 && y == n-1) return d;
            for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                if (dist[nx][ny] > d + 1){
                    dist[nx][ny] = d + 1;
                    q.push({d+1,{nx,ny}});
                }

            }
            }
        }
        return -1;  
    }
};