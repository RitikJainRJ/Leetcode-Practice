class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(mat.size() == 0 || mat[0].size() == 0)
            return 0;
        int n = mat.size(), m = mat[0].size(), res = 0;
        int dp[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                dp[i][j] = (mat[i][j] - '0');
                if(i && j && mat[i][j] == '1')
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                res = max(res, dp[i][j]);
            }
        return res * res;
    }
};
