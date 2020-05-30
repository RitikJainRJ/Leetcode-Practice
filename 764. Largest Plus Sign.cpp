class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> mat(n, vector<int>(n, 1));
        int res = 0;
        int u[n][n], l[n][n], r[n][n], d[n][n];

        for(int i = 0; i < mines.size(); i++)
            mat[mines[i][0]][mines[i][1]] = 0;
        for(int i = 0; i < n; i++){
            u[0][i] = mat[0][i];
            d[n - 1][i] = mat[n - 1][i];
            l[i][0] = mat[i][0];
            r[i][n - 1] = mat[i][n - 1];
        }
        for(int i = 1; i < n; i++)
            for(int j = 0; j < n; j++){
                u[i][j] = mat[i][j] ? mat[i][j] + u[i - 1][j] : 0;
                d[n - 1 - i][j] = mat[n - 1 - i][j] ? mat[n - 1 - i][j] + d[n - i][j] : 0;
                l[j][i] = mat[j][i] ? mat[j][i] + l[j][i - 1] : 0;
                r[j][n - 1 - i] = mat[j][n - 1 - i] ? mat[j][n - 1 - i] + r[j][n - i] : 0;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res = max(res, min({u[i][j], l[i][j], r[i][j], d[i][j]}));
        return res;
    }
};
