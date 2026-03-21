class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftmax = 0;
        int rightmax = 0;
        int waterr = 0;
        int water = 0;
        while (l<r){
            if(height[l] <= height[r]){
            int a = min(height[l],height[r]);
            int b = r-l;
            waterr = a*b;
            water = max(water,waterr);
            l++;
            }
            else{
            int a = min(height[l],height[r]);
            int b = r-l;
            waterr = a*b;
            water = max(water,waterr);
            r--;
            }
        }
        return water;
        
    }
};