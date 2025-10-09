#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

class Solution {
public:
    int kruskal(int n, vector<vector<int>>& edges, int skipEdge = -1, int includeEdge = -1) {
        DSU dsu(n);
        int total = 0, count = 0;

        // if we must include an edge first
        if (includeEdge != -1) {
            total += edges[includeEdge][2];
            dsu.unite(edges[includeEdge][0], edges[includeEdge][1]);
            count++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skipEdge) continue;
            if (dsu.unite(edges[i][0], edges[i][1])) {
                total += edges[i][2];
                count++;
            }
        }

        return (count == n - 1) ? total : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; i++) edges[i].push_back(i); 
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        int base = kruskal(n, edges); 
        vector<int> critical, pseudo;

        for (int i = 0; i < m; i++) {
            int without = kruskal(n, edges, i, -1);
            if (without > base) {
                critical.push_back(edges[i][3]);
            } else {
                int with = kruskal(n, edges, -1, i);
                if (with == base) pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};
