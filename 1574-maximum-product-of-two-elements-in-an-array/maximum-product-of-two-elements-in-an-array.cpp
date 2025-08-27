class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result; 
        int maxi;
        for (int i = 0;i<n ; i++){
            for (int j =i+1 ; j<n ;j++){
                result = (nums[i]-1)*(nums[j]-1);
                maxi = max (result,maxi);
            }
        }
        return maxi;
        
    }
};