class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (requiredTime(piles, mid, h) <= h) {
                result = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }
        return result;
    }
    private:
    int requiredTime(vector<int>& piles, int k,int h) {
        int total_hours = 0;
        for (int bananas : piles) {
            total_hours += (bananas + (long long)k - 1)/ k; 
            if (total_hours > h) return total_hours; 
        }
        return total_hours;    
    }
};