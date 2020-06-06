class Solution {
private:
    void solve(vector<vector<int>>& grid, int x, int y, int &res, int c, int count){
        if(grid[x][y] == 2){
            if(count + 1 == c)
                res++;
            return;
        }
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        int orig = grid[x][y];

        grid[x][y] = -2;
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < grid.size() && 0 <= _y && _y < grid[_x].size() && (grid[_x][_y] == 0 || grid[_x][_y] == 2)){
                solve(grid, _x, _y, res, c + 1, count);
            }
        }
        grid[x][y] = orig;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0, count = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 0)
                    count++;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1){
                    solve(grid, i, j, res, 0, count);
                    break;
                }
        return res;
    }
};
