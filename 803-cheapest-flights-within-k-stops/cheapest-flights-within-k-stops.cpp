class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);// adjacency list shit
        for (auto& flight : flights) {
            int u = flight[0], v = flight[1], price = flight[2];
            graph[u].emplace_back(v, price);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // cost bhi pehle rakh sakte hai jese hi stop k se jyada hoga aage badh jayenge
        pq.emplace(0, src, 0); 
        vector<int> minStops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();

            if (city == dst) return cost; // destination reached :)

            if (stops > k || stops >= minStops[city]) continue;
            // agar stops jyada aagya pehle wale stop se toh fir usko considr nahi karenge kam aayega toh woh store karenge replace krke aur in case stop allowed stop se jyada aagya tab toh bilkul hi aage badh jayenge
            minStops[city] = stops;

            for (auto& [nei, price] : graph[city]) {
                pq.emplace(cost + price, nei, stops + 1);
            }
        }

        return -1;
        
    }
};