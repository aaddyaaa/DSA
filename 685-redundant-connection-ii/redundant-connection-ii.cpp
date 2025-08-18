class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n+1), rank(n+1, 0) {
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false; // cycle detected

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true; // union done
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> cand1, cand2;

        // Step 1: detect node with two parents
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // v has two parents
                cand1 = {parent[v], v}; // earlier edge
                cand2 = {u, v};         // later edge
                e[1] = 0; // temporarily invalidate later edge
            }
        }

        // Step 2: Union-Find to detect cycle
        UnionFind uf(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (v == 0) continue; // skip temporarily removed edge

            if (!uf.unite(u, v)) { 
                // cycle detected
                if (cand1.empty()) return e; // no two-parent case
                return cand1; // two-parent case: remove earlier edge
            }
        }

        // No cycle detected: remove later edge
        return cand2;
    }
};