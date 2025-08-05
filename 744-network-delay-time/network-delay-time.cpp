class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for (auto time:times){
            int u = time[0], v= time[1], w= time[2];
            graph[u].emplace_back(v,w);
        }
        vector <int> timee(n + 1, INT_MAX);
        timee[k] = 0;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0,k}); // time, current node
        while(!pq.empty()){
            auto [currtime,u] = pq.top(); pq.pop();
            for (auto [nodee,cost] : graph[u]){
                if (cost+currtime<timee[nodee]){
                    timee[nodee] = cost + currtime;
                    pq.push({timee[nodee],nodee});
                }
            }
            
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
        if (timee[i] == INT_MAX) return -1; // Unreachable node
        maxTime = max(maxTime, timee[i]);
        }
        return maxTime;
    }
};