class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    unordered_map<int, int> orMap;  

    for (int i = n - 1; i >= 0; --i) {
        unordered_map<int, int> newMap;
        newMap[nums[i]] = 1;

        for (auto& [orVal, len] : orMap) {
            int newOr = orVal | nums[i];
            if (newMap.find(newOr) == newMap.end()) {
                newMap[newOr] = len + 1;
            } else {
                newMap[newOr] = min(newMap[newOr], len + 1);
            }
        }

        int maxOr = 0;
        int minLen = n;
        for (auto& [orVal, len] : newMap) {
            if (orVal > maxOr) {
                maxOr = orVal;
                minLen = len;
            } else if (orVal == maxOr) {
                minLen = min(minLen, len);
            }
        }

        result[i] = minLen;
        orMap = move(newMap); 
    }

    return result;
        
    }
};