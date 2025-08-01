class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis)) return true;
            } else if (pathVis[neighbor]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        // Build directed graph
        for (auto edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v); // edge: u -> v
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return false; // cycle -> cannot finish
            }
        }

        return true;
    }
};
