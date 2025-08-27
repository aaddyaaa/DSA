class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> final;   
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            int discount = prices[i];   
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    discount = prices[i] - prices[j];
                    break;
                }
            }
            final.push_back(discount);
        }

        return final;

    }
};
