class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] > b[1]; 
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int tv = 0;
        int n = boxTypes.size();
        for (int i = 0 ; i<n ; i++){
            int boxes = boxTypes[i][0];
            int units = boxTypes[i][1];
            if (boxes<=truckSize){
                tv+= boxes*units;
                truckSize-=boxes;
            }
            else {
                tv+= truckSize * units; // left no of boxes that truck can intake and multiplying it with value of that particular element in array jaha pr else aaya
                break;
            }
        }
        return tv;
    }
};