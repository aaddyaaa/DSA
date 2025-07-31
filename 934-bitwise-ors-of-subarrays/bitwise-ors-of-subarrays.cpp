class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
    set<int> prev;

    for (int num : arr) {
        set<int> cur;
        cur.insert(num);
        for (int x : prev) {
            cur.insert(x | num);
        }
        prev = cur;
        result.insert(cur.begin(), cur.end());
    }

    return result.size();
        
    }
};