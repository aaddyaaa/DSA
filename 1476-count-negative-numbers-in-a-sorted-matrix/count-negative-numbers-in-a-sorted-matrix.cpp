class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int target = -1;
        int n = grid.size();
        int count = 0;
        for (int i = 0  ; i< n ; i++){
            int l = 0;
            int r = grid[i].size()-1;
            while (l<=r){
               int mid = l + (r - l) / 2;
               if (grid[i][mid] >= 0){
                  l = mid + 1;
                }
               else r = mid - 1;
            }
            count += grid[i].size() - l;
        }
        return count;
    }
};