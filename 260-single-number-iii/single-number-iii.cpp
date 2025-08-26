class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int n : nums) xorAll ^= n;

        long long diff = xorAll & -(long long)xorAll;

        int x = 0, y = 0;
        for (int n : nums) {
            if (n & diff) x ^= n;  
            else y ^= n;         
        }

        return {x, y};

    }
};