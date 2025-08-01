class Solution {
private:
    static void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis){
        vis[node] = 1;
        for (auto it : adjLs[node]){
            if (!vis[it]){
                dfs(it, adjLs, vis);
            }
        }

    }
public:
    static int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();  // or adj.size()
        // Step 1: Convert adjacency matrix to adjacency list
        vector<vector<int>> adjLs(V);  // dynamic 2D vector
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);  // undirected graph
                }
            }
        }
        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, adjLs, vis);
        }
        }
        return cnt;

    }
};