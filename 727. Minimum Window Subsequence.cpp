#define ll unsigned long long
class Solution {
public:
    string minWindow(string &s, string &t) {
        int n1 = s.length(), n2 = t.length(), c, m = INT_MAX;
        ll dp[n2 + 1][n1 + 1];
        string res;

        for(int i = 0; i <= n1; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= n2; i++)
            dp[i][0] = INT_MAX;
        for(int i = 1; i <= n2; i++){
            for(int j = 1; j <= n1; j++){
                dp[i][j] = t[i - 1] == s[j - 1] ? 1 + min(dp[i - 1][j - 1], dp[i][j - 1]) : 1 + dp[i][j - 1];
                if(i == n2 && m > dp[i][j])
                    m = dp[i][j], c = j;
            }
        }
        if(m == INT_MAX)
            return res;
        res = s.substr(c - m, m);
        return res;
    }
};
