class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0); 
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; 

        UnionFind uf(n);
        for (auto &conn : connections) {
            uf.unite(conn[0], conn[1]);
        }

        unordered_set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(uf.find(i));
        }

        return components.size() - 1; // Minimum operations needed
    }
};
