class Solution {
private:
    int bfs(vector<vector<int>> &forest, int x, int y, int tx, int ty){
        int n = forest.size(), m = forest[0].size();
        queue<pair<int, int>> q;
        int vis[n][m];
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        memset(vis, -1, sizeof(vis));
        q.push({x, y});
        vis[x][y] = 0;
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second, dis = vis[x][y];
            if(x == tx && y == ty)
                return dis;
            for(int i = 0; i < 4; i++){
                int _x = x + xMove[i];
                int _y = y + yMove[i];
                if(0 <= _x && _x < n && 0 <= _y && _y < m && vis[_x][_y] == -1 && forest[_x][_y] != 0){
                    vis[_x][_y] = dis + 1;
                    q.push({_x, _y});
                }
            }
        }
        return -1;
    }

public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size(), m = forest[0].size(), res = 0;
        vector<vector<int>> trees;

        if(n == 0 || m == 0 || forest[0][0] == 0)
            return -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());
        int x = 0, y = 0;
        for(int i = 0; i < trees.size(); i++){
            int dis = bfs(forest, x, y, trees[i][1], trees[i][2]);
            if(dis == -1)
                return -1;
            res += dis;
            x = trees[i][1];
            y = trees[i][2];
        }
        return res;
    }
};
