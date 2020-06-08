class Solution {
private:
    void _solve(vector<vector<char>> &board, int x, int y){
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};

        board[x][y] = '$';
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < board.size() && 0 <= _y && _y < board[_x].size() && board[_x][_y] == 'O')
                _solve(board, _x, _y);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                _solve(board, i, 0);
            if(board[i][m - 1] == 'O')
                _solve(board, i, m - 1);
        }
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O')
                _solve(board, 0, i);
            if(board[n - 1][i] == 'O')
                _solve(board, n - 1, i);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                if(board[i][j] == '$')  board[i][j] = 'O';
            }
    }
};
