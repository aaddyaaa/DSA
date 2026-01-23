class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        unordered_set<int> s(begin(nums1), end(nums1));
        for (int x : nums2) {
        if (s.find(x) != s.end()) {
            return x;
        }
        }
        int a = nums1[0];
        int b = nums2[0];

        if (a < b)
            return a * 10 + b;
        else
            return b * 10 + a;
    }
};