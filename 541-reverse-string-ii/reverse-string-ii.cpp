class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0;i<n;i+=2*k){
            int left = i;
            int j = min(i+k-1, n-1);
            int right = j;
            while (left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
            }
            
        }
    return s;      
    }
};