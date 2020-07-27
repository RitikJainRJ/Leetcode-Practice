class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int n = prices.size();
        int left[n], right[n], res = 0;

        left[0] = 0, right[n - 1] = 0;
        int lmin = prices[0], rmax = prices[n - 1];
        for(int i = 1; i < n; i++){
            lmin = min(lmin, prices[i]);
            left[i] = max(left[i - 1], prices[i] - lmin);
            rmax = max(rmax, prices[n - 1 - i]);
            right[n - 1 - i] = max(right[n - i], rmax - prices[n - 1 - i]);
        }
        for(int i = 0; i < n; i++)
            res = max(res, left[i] + right[i]);
        return res;
    }
};
