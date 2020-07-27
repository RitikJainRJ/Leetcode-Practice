class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        int dp[k + 1][n + 1], prev;

        for(int i = 0; i <= n; i++)
            dp[0][i] = 0;
        for(int i = 0; i <= k; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= k; i++){
            prev = INT_MIN;
            for(int j = 1; j <= n; j++){
                prev = max(prev, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], prev + prices[j - 1]);
            }
        }
        return dp[k][n];
    }
};
