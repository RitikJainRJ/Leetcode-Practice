class Solution {
public:
    void _numIslands(int x, int y, vector<vector<char>> &grid){
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        grid[x][y] = '0';
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < grid.size() && 0 <= _y && _y < grid[_x].size() && grid[_x][_y] == '1'){
                _numIslands(_x, _y, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == '1'){
                    res++;
                    _numIslands(i, j, grid);
                }
        return res;
    }
};
