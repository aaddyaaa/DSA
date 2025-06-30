class Solution {
private: 
    static bool comp(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1]; //ascending 1 means end 0 means start
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

    sort(points.begin(), points.end(), comp);

    int arrows = 1;
    int lastArrow = points[0][1];  

    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > lastArrow) {
            arrows++;
            lastArrow = points[i][1];
        }
        
    }
    return arrows;
    }
};