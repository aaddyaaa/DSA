class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0; 
        for (int x : nums1) sum1 += x;
        for (int x : nums2) sum2 += x;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0;i<nums1.size();i++){
            if (nums1[i]==0){
                cnt1++;
            }
        }
        for (int i = 0;i<nums2.size();i++){
            if (nums2[i]==0){
                cnt2++;
            }
        }
        if (cnt1 == 0 && cnt2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        }
        if (cnt1 == 0 && sum1 < sum2 + cnt2) return -1;
        if (cnt2 == 0 && sum2 < sum1 + cnt1) return -1;
        return max(sum1+cnt1 , sum2+cnt2);
    }
};