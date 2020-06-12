#define ll unsigned long long

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        ll dp[n1 + 1][n2 + 1];

        for(int i = 0; i <= n1; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= n2; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++){
                dp[i][j] = dp[i - 1][j];
                if(s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        return (int)dp[n1][n2];
    }
};
