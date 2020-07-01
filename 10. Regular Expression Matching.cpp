class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        int dp[n + 1][m + 1];

        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        dp[0][0] = true;
        for(int i = 1; i <= n; i++)
            dp[i][0] = false;
        for(int i = 1; i <= m; i++)
            if(p[i - 1] == '*'){
                dp[0][i] = dp[0][i - 1];
                i++;
                dp[0][i] = dp[0][i - 1];
            }
            else
                dp[0][i] = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(p[j - 1] == '.' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*'){
                    if(p[j] == '.' || p[j] == s[i - 1]){
                        dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
                        j++;
                        dp[i][j] = dp[i][j - 1];
                    }
                    else{
                        dp[i][j] = dp[i][j - 1];
                        j++;
                        dp[i][j] = dp[i][j - 1];
                    }
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};
