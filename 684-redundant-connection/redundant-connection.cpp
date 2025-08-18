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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        vector<int> ans;
        for (auto ed : edges){
            if (!uf.unite(ed[0], ed[1])) return ed; 
        }
        return {};
    }
};