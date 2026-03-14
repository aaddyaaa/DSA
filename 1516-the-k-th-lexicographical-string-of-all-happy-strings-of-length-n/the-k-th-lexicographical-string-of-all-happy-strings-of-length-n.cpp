class Solution {
public:
    int count = 0;
    string answer = "";
    void solve(string curr, int n ,int k){
        if (curr.size()== n){
            count++;
        if (count == k){
            answer = curr;
        }
        return ;
        }
        for (char ch : {'a','b','c'}){
            if (curr.empty() || curr.back()!= ch){
                solve(curr+ch, n, k);
            }
        }
    }

    string getHappyString(int n, int k) {
        solve("", n, k);
        return answer;
    }
};