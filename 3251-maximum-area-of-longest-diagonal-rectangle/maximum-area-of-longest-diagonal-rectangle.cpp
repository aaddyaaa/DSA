class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int bestDiag = -1;
        int bestArea = -1;

        for (auto& rect : dimensions) {
            int l = rect[0], w = rect[1];
            int diag = l * l + w * w;
            int area = l * w;

            if (diag > bestDiag || (diag == bestDiag && area > bestArea)) {
                bestDiag = diag;
                bestArea = area;
            }
        }
        return bestArea;
        
    }
};