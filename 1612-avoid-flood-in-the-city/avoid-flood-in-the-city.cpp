class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // initialize dry days to 1 (any lake)
        unordered_map<int, int> lakeDay; // lake -> last day it rained
        set<int> dryDays; // indices of dry days (0s)

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) { // rain day
                int lake = rains[i];

                if (lakeDay.count(lake)) {
                    // Find a dry day between last rain and today
                    auto it = dryDays.upper_bound(lakeDay[lake]);
                    if (it == dryDays.end()) {
                        // no dry day available → flood
                        return {};
                    }
                    ans[*it] = lake; // dry this lake on that day
                    dryDays.erase(it);
                }

                lakeDay[lake] = i; // mark lake as full today
                ans[i] = -1; // rain day
            } else {
                dryDays.insert(i); // store dry day index
            }
        }

        return ans;
    }
};