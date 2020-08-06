class Solution {
public:
    double knightProbability(int n, int m, int r, int c) {
        int xMove[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int yMove[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        double dp[n][n][m + 1];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j][0] = 1.0;
        for(int s = 1; s <= m; s++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dp[i][j][s] = 0.0;

                    for(int k = 0; k < 8; k++){
                        int nx = i + xMove[k];
                        int ny = j + yMove[k];

                        if(0 <= nx && nx < n && 0 <= ny && ny < n)
                            dp[i][j][s] += dp[nx][ny][s - 1] / 8.0;
                    }
                }
            }
        }
        return dp[r][c][m];
    }
};
