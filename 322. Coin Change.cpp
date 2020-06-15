class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n + 1][amount + 1];

        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= amount; i++)
            dp[0][i] = INT_MAX;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i - 1][j];
                if(coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INT_MAX)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
        if(dp[n][amount] == INT_MAX)
            return -1;
        return dp[n][amount];
    }
};
