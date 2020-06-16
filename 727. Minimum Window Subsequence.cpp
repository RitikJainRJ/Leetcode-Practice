class Solution {
public:
    string minWindow(string &s, string &t) {
        int n1 = s.length(), n2 = t.length();
        string res;
        int dp[n2 + 1][n1 + 1], c, m = INT_MAX;

        for(int i = 0; i <= n1; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= n2; i++)
            dp[i][0] = INT_MAX;
        for(int i = 1; i <= n2; i++){
            for(int j = 1; j <= n1; j++){
                dp[i][j] = dp[i][j - 1] != INT_MAX ? 1 + dp[i][j - 1] : dp[i][j - 1];
                if(t[i - 1] == s[j - 1] && dp[i - 1][j - 1] != INT_MAX)
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
                if(i == n2 && m > dp[i][j]){
                    m = dp[i][j];
                    c = j;
                }
            }
        }
        if(dp[n2][n1] == INT_MAX)
            return res;
        int i = n2, j = c, k = t.length();
        while(k){
            if(t[i - 1] == s[j - 1]){
                if(dp[i][j - 1] > dp[i - 1][j - 1]){
                    i--;
                    k--;
                }
            }
            j--;
        }
        res = s.substr(j, c - j);
        return res;
    }
};
