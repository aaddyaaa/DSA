class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(), [](const vector<int>&a,const vector<int>&b){ 
            return a[1]<b[1];
        });
        int cnt = 0;
        int lt = intervals[0][1];
        for (int i = 1 ; i<n;i++){
            if (intervals[i][0]<lt){
                cnt++;
            }
            else lt = intervals[i][1];
        }
        return cnt;
    }
};