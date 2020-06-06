class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), temp;
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return 0;
        temp = 1;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1)
                temp = -1;
            grid[i][0] = temp;
        }
        temp = 1;
        for(int i = 1; i < m; i++){
            if(grid[0][i] == 1)
                temp = -1;
            grid[0][i] = temp;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                    continue;
                }
                int a = grid[i - 1][j] == -1 ? 0 : grid[i - 1][j];
                int b = grid[i][j - 1] == -1 ? 0 : grid[i][j - 1];                                               grid[i][j] = a + b;
            }
        }
        return grid[n - 1][m - 1];
    }
};
