class Solution {
public:
    pair<int, vector<int>> bfs(int start, int n, vector<vector<int>>& adj) {
        vector<int> parent(n, -1);
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farthest = start;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            farthest = node;  
            for (int nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    parent[nei] = node;
                    q.push(nei);
                }
            }
        }
        return {farthest, parent};
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto [u, _] = bfs(0, n, adj);
        auto [v, parent] = bfs(u, n, adj);
        vector<int> path;
        int cur = v;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        int m = path.size();
        if (m % 2 == 1) {
            return { path[m/2] };        
        } else {
            return { path[m/2], path[m/2 - 1] }; 
        }
    }
};