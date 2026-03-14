class Solution {
public:

    bool canfinish(long long T, int mountainHeight, vector<int>& workerTimes) {
        long long totalHeight = 0;

        for (int t : workerTimes) {

            long long x = (-1 + sqrt(1 + (8.0 * T) / t)) / 2;

            totalHeight += x;

            if (totalHeight >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low = 0;

        long long maxTime = *min_element(workerTimes.begin(), workerTimes.end());
        long long high = maxTime * 1LL * mountainHeight * (mountainHeight + 1) / 2;

        long long answer = high;

        while (low <= high) {

            long long mid = (low + high) / 2;

            if (canfinish(mid, mountainHeight, workerTimes)) {
                answer = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return answer;
    }
};