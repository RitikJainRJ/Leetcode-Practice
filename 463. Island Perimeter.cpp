class Solution {
public:
    void _perimeter(int x, int y, vector<vector<int>> &grid, int &res){
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        grid[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(!(0 <= _x && _x < grid.size() && 0 <= _y && _y < grid[_x].size()))
                res++;
            else if(grid[_x][_y] == 0)
                res++;
        }
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < grid.size() && 0 <= _y && _y < grid[_x].size() && grid[_x][_y] == 1)
                _perimeter(_x, _y, grid, res);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1){
                    _perimeter(i, j, grid, res);
                    break;
                }
        return res;
    }
};
