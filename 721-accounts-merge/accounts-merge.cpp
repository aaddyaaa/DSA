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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToID;  // map email -> unique id
        unordered_map<string, string> emailToName;  // map email -> name
        int id = 0;

        // Assign a unique id to each email
        for (auto &acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (emailToID.find(email) == emailToID.end()) {
                    emailToID[email] = id++;
                    emailToName[email] = name;
                }
            }
        }

        UnionFind uf(id);

        // Union emails in the same account
        for (auto &acc : accounts) {
            int firstID = emailToID[acc[1]];
            for (int i = 2; i < acc.size(); i++) {
                uf.unite(firstID, emailToID[acc[i]]);
            }
        }

        // Group emails by ultimate parent
        unordered_map<int, set<string>> components;
        for (auto &p : emailToID) {
            string email = p.first;
            int parentID = uf.find(p.second);
            components[parentID].insert(email);
        }

        // Build the merged accounts
        vector<vector<string>> res;
        for (auto &p : components) {
            vector<string> merged;
            string name = emailToName[*p.second.begin()];
            merged.push_back(name);
            merged.insert(merged.end(), p.second.begin(), p.second.end());
            res.push_back(merged);
        }

        return res;
    }
};