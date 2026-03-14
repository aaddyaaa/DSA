class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        priority_queue<
            pair<long long, pair<long long,long long>>,
            vector<pair<long long, pair<long long,long long>>>,
            greater<>
        > pq;

        for(long long t : workerTimes){
            pq.push({t, {t, 1}});
        }

        long long ans = 0;

        for(int i = 0; i < mountainHeight; i++){
            auto top = pq.top();
            pq.pop();

            long long time = top.first;
            long long t = top.second.first;
            long long k = top.second.second;

            ans = time;

            long long nextTime = time + (k + 1) * t;
            pq.push({nextTime, {t, k + 1}});
        }

        return ans;
    }
};