class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];

        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
            for(int j = 1; j * j <= i; j++)
                if(i - j >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
        return dp[n];
    }
};
