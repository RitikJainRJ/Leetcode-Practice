class Solution {
private:
    void solve(vector<vector<int>> &rooms, int x, int y, int c){
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        rooms[x][y] = c;
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < rooms.size() && 0 <= _y && _y < rooms[_x].size() && c + 1 < rooms[_x][_y]){
                solve(rooms, _x, _y, c + 1);
            }
        }
    }

public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        if(rooms.size() == 0 && rooms[0].size() == 0)
            return;
        int m = rooms.size(), n = rooms[0].size();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0)
                    solve(rooms, i, j, 0);
    }
};
