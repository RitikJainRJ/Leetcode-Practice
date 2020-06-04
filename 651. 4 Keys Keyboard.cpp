class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1);

        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = 1 + dp[i - 1];
            for(int j = i - 3, k = 2; j > 0; j--, k++)
                dp[i] = max(dp[i], dp[j] * k);
        }
        return dp[n];
    }
};
