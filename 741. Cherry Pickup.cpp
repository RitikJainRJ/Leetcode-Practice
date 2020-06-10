class Solution {
private:
    int dfs(int r1, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int n){
        int r2 = r1 + c1 - c2;
        int ans;

        if(r1 == n || r2 == n || c1 == n || c2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if(r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
        if(dp[r1][c1][c2] != INT_MIN)
            return dp[r1][c1][c2];
        ans = grid[r1][c1];
        if(c1 != c2)
            ans += grid[r2][c2];
        ans += max({dfs(r1 + 1, c1, c2, grid, dp, n), dfs(r1, c1 + 1, c2, grid, dp, n),
                    dfs(r1 + 1, c1, c2 + 1, grid, dp, n), dfs(r1, c1 + 1, c2 + 1, grid, dp, n)});
        dp[r1][c1][c2] = ans;
        return ans;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));

        return max(0, dfs(0, 0, 0, grid, dp, n));
    }
};
