class Solution {
public:

    bool canfinish(long long T, int mountainHeight, vector<int>& workerTimes){
        long long totalHeight = 0;

        for(int t : workerTimes){
            
            long long low = 0;
            long long high = mountainHeight;
            long long best = 0;

            while(low <= high){
                long long mid = (low + high) / 2;

                long long timeNeeded = (long long)t * (mid * (mid + 1) / 2);

                if(timeNeeded <= T){
                    best = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            totalHeight += best;

            if(totalHeight >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low = 0;
        long long high = (long long)*max_element(workerTimes.begin(), workerTimes.end()) * mountainHeight * (mountainHeight + 1) / 2;

        long long answer = high;

        while(low <= high){

            long long mid = (low + high) / 2;

            if(canfinish(mid, mountainHeight, workerTimes)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return answer;
    }
};