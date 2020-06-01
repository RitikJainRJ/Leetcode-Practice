#define pii pair<int, int>

class Solution {
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        if(maze.size() == 0 || maze[0].size() == 0)
            return -1;
        int n = maze.size(), m = maze[0].size();
        int dp[n][m];
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        queue<pii> q;

        memset(dp, -1, sizeof(dp));
        dp[start[0]][start[1]] = 0;
        q.push({start[0], start[1]});
        while(!q.empty()){
            pii front = q.front();
            q.pop();
            int x = front.first, y = front.second;

            if(x == destination[0] && y == destination[1])
                return dp[x][y];
            for(int i = 0; i < 4; i++){
                int count = 0;
                int _x = x + xMove[i];
                int _y = y + yMove[i];
                while(0 <= _x && _x < maze.size() && 0 <= _y && _y < maze[_x].size() && maze[_x][_y] != 1){
                    count++;
                    _x = _x + xMove[i];
                    _y = _y + yMove[i];
                }
                _x = _x - xMove[i];
                _y = _y - yMove[i];
                if(dp[_x][_y] == -1){
                    dp[_x][_y] = dp[x][y] + count;
                    q.push({_x, _y});
                }
            }
        }
        return -1;
    }
};
