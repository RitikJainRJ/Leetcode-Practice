#define vvi vector<vector<int>>
#define pii pair<int, int>
class Solution {
public:
    int orangesRotting(vvi &grid) {
        int n = grid.size(), m = grid[0].size();
        vvi dp(n, vector<int>(m, INT_MAX));
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        queue<pii> q;
        int res = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 2)
                    dp[i][j] = 0, q.push({i, j});
        while(!q.empty()){
            pii f = q.front();
            q.pop();
            int x = f.first, y = f.second;
            int d = dp[x][y];

            for(int i = 0; i < 4; i++){
                int nx = x + xMove[i];
                int ny = y + yMove[i];
                if(0 <= nx && nx < grid.size() && 0 <= ny && ny < grid[nx].size() && grid[nx][ny] == 1 && d + 1 < dp[nx][ny])
                    dp[nx][ny] = 1 + d, q.push({nx, ny});
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(dp[i][j] == INT_MAX && grid[i][j] == 1)
                    return -1;
                else if(grid[i][j] == 1)
                    res = max(res, dp[i][j]);
        return res;
    }
};
