class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        static constexpr int INF = INT_MAX / 2;

        struct Trie {
            Trie* child[26];
            int id;
            Trie() : id(-1) {
                memset(child, 0, sizeof(child));
            }
        };

        auto addWord = [&](Trie* root, const string& s, int& cnt) {
            Trie* cur = root;
            for (char c : s) {
                int i = c - 'a';
                if (!cur->child[i]) cur->child[i] = new Trie();
                cur = cur->child[i];
            }
            if (cur->id == -1) cur->id = ++cnt;
            return cur->id;
        };

        int n = source.size();
        int m = original.size();

        Trie* root = new Trie();
        int idCnt = -1;

        vector<pair<int,int>> edges;
        for (int i = 0; i < m; ++i) {
            int u = addWord(root, original[i], idCnt);
            int v = addWord(root, changed[i], idCnt);
            edges.emplace_back(u, v);
        }

        int V = idCnt + 1;
        vector<vector<int>> dist(V, vector<int>(V, INF));
        for (int i = 0; i < V; ++i) dist[i][i] = 0;

        for (int i = 0; i < m; ++i) {
            auto [u, v] = edges[i];
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        for (int k = 0; k < V; ++k)
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<long long> dp(n, -1);

        auto relax = [&](long long& x, long long y) {
            if (x == -1 || y < x) x = y;
        };

        for (int s = 0; s < n; ++s) {
            if (s > 0 && dp[s - 1] == -1) continue;
            long long base = (s == 0 ? 0 : dp[s - 1]);

            if (source[s] == target[s]) {
                relax(dp[s], base);
            }

            Trie* u = root;
            Trie* v = root;

            for (int e = s; e < n; ++e) {
                u = u->child[source[e] - 'a'];
                v = v->child[target[e] - 'a'];
                if (!u || !v) break;

                if (u->id != -1 && v->id != -1 && dist[u->id][v->id] < INF) {
                    relax(dp[e], base + dist[u->id][v->id]);
                }
            }
        }

        return dp[n - 1];
    }
};
