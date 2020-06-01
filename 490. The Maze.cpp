class Solution {
private:
    bool _hasPath(vector<vector<int>> &maze, int x, int y, vector<int> &des){
        if(x == des[0] && y == des[1])
            return true;
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        maze[x][y] = -1;
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            while(0 <= _x && _x < maze.size() && 0 <= _y && _y < maze[_x].size() && maze[_x][_y] != 1){
                _x = _x + xMove[i];
                _y = _y + yMove[i];
            }
            _x = _x - xMove[i];
            _y = _y - yMove[i];
            if(maze[_x][_y] == 0 && _hasPath(maze, _x, _y, des))
                return true;
        }
        return false;
    }

public:
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        return _hasPath(maze, start[0], start[1], destination);
    }
};
