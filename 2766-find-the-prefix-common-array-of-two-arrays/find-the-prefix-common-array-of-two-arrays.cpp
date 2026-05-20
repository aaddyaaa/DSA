class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        unordered_map<int, int> freq;
        for(int i = 0;i <n ; i++){
            freq[A[i]]++;
            freq[B[i]]++;
            for(auto &it : freq){
                if(it.second > 1){
                    ans[i]++;
                }
            }
        }
        return ans;

    }
};