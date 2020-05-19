class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();

        int i = 0, j;
        for(j = 1; j < n; j++){
            if(prices[j - 1] < prices[j])
                continue;
            res += prices[j - 1] - prices[i];
            i = j;
        }
        if(prices[i] < prices[j - 1])
            res += prices[j - 1] - prices[i];
        return res;
    }
};
