class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];

        for(int i = 0; i < n; i++)
            dp[i][i] = 0;
        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                if(l == 2)
                    dp[i][j] = s[i] == s[j] ? 0 : 1;
                else
                    dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 1 + min(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};
