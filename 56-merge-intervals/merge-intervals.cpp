class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // start time sort

        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Merge all overlapping intervals
            while (i + 1 < n && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            res.push_back({start, end});
            i++;
        }

        return res;
    }
};