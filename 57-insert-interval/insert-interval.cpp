class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while (i<n && intervals[i][1]<newInterval[0]) {
            // kisi bhi element ka last agar new interval ke start se chhota hai toh non overlapping hai usko add krdo direct res me;
        res.push_back(intervals[i]);
        i++;
        }
        while (i<n && intervals[i][0]<=newInterval[1]){
            // kisi bhi interval ka last new wale ke first se chhota hai toh overlapping hai uske liye niyam hai kuch;
            newInterval[0]=min( newInterval[0],intervals[i][0]);
            newInterval[1]=max( newInterval[1],intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};