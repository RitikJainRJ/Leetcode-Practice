#define pii pair<int, int>

class Solution {
private:
    int bfs(vector<vector<int>> &grid, int r, int c, int count){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int res = 0;
        queue<pii> q;
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        dist[r][c] = 0;
        q.push({r, c});
        while(!q.empty()){
            int size = q.size();

            while(size--){
                pii f = q.front();
                q.pop();
                int x = f.first, y = f.second;

                for(int i = 0; i < 4; i++){
                    int nx = x + xMove[i];
                    int ny = y + yMove[i];
                    if(0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] == INT_MAX){
                        if(grid[nx][ny] == 1){
                            dist[nx][ny] = 1 + dist[x][y];
                            res += dist[nx][ny];
                            count--;
                        }
                        else if(grid[nx][ny] == 0){
                            dist[nx][ny] = 1 + dist[x][y];
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return count == 0 ? res : INT_MAX;
    }

public:
    int shortestDistance(vector<vector<int>> &grid) {
        int res = INT_MAX, c= 0;

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1)
                    c++;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 0){
                    res = min(res, bfs(grid, i, j, c));
                }
        return res;
    }
};
