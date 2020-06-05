class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool dp[n][n];
        int c[n];

        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int l = 2; l <= n; l++)
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                if(l == 2)
                    dp[i][j] = s[i] == s[j] ? true : false;
                else
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1] ? true : false;
            }
        c[0] = 0;
        for(int i = 1; i < n; i++){
            if(dp[0][i])
                c[i] = 0;
            else{
                c[i] = INT_MAX;
                for(int j = 0; j < i; j++)
                    if(dp[j + 1][i] && c[j] + 1 < c[i])
                        c[i] = c[j] + 1;
            }
        }
        return c[n - 1];
    }
};
