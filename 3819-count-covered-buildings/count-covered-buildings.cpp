class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row, col;
        for (auto &b : buildings) {
            row[b[1]].push_back(b[0]);
            col[b[0]].push_back(b[1]);
        }
        for (auto &p : row) sort(p.second.begin(), p.second.end());
        for (auto &p : col) sort(p.second.begin(), p.second.end());

        int covered = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &r = row[y];
            auto &c = col[x];
            int ix = lower_bound(r.begin(), r.end(), x) - r.begin();
            int iy = lower_bound(c.begin(), c.end(), y) - c.begin();
            if (ix > 0 && ix < r.size() - 1 && iy > 0 && iy < c.size() - 1)
                covered++;
        }
        return covered;
    }
};
