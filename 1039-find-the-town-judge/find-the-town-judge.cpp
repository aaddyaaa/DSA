class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1 ,0);
        vector<int> outdegree(n+1 ,0);
        int non = trust.size();
         for (int i = 0 ; i<non ; i++){
            int a = trust[i][0];
            int b = trust[i][1];
            indegree[b]++;
            outdegree[a]++;
         }
         for (int i = 1 ; i<=n ; i++){
            if (indegree[i]==n-1 && outdegree[i]==0){
                return i;
            }
         }
        return -1;
    }
};