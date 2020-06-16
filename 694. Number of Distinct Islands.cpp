class Solution {
private:
    void _islands(vector<vector<int>> &grid, int x, int y, string &ans){
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        char d[] = {'u', 'r', 'd', 'l'};
        char r[] = {'d', 'l', 'u', 'r'};

        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];

            if(0 <= _x && _x < grid.size() && 0 <= _y && _y < grid[_x].size() && grid[_x][_y] == 1){
                ans += d[i];
                _islands(grid, _x, _y, ans);
                ans += r[i];
            }
        }

    }

public:
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        unordered_set<string> us;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    string ans;
                    _islands(grid, i, j, ans);
                    cout << ans << " ";
                    if(us.find(ans) == us.end()){
                        res++;
                        us.insert(ans);
                    }
                }
            }
        return res;
    }
};
