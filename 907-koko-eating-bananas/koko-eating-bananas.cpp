class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (piles[i] > maxi) {
                maxi = piles[i];
            }
        }

        int low = 1;
        int high = maxi;
        int answer = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalHours = 0;
            for (int i = 0; i < n; i++) {
                totalHours += (piles[i] + mid - 1) / mid; 
            }

            if (totalHours <= h) {
                answer = mid;        // try smaller speed
                high = mid - 1;
            } else {
                low = mid + 1;       // need more speed
            }
        }

        return answer;
        
    }
};