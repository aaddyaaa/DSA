class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = prices.size();
        int adyu = prices[0];
        int profitt = 0;
        int profit = 0;
        for (int i = 0;i<p; i++){
            adyu = min(adyu, prices[i]);
            profitt = prices[i]- adyu;
            profit = max(profitt, profit);
        }
        return profit;
    }
};