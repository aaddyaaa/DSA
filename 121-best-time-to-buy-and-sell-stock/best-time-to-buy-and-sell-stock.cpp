class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices [0];
        int profit = 0;
        for (int i=1; i<prices.size(); i++){
            int cost_buy = prices[i]-mini;
            profit = max(profit,cost_buy);
            mini = min (mini,prices[i]);
        }

    
     return profit;
    }

};