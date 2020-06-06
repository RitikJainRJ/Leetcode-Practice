class Solution {
private:
    bool isSafe(int x, int y, vector<vector<char>> &board, int num){
        for(int i = 0; i < 9; i++){
            if(board[x][i] == num + '0')
                return false;
            if(board[i][y] == num + '0')
                return false;
        }
        x = x - x % 3, y = y - y % 3;
        for(int i = x; i < x + 3; i++)
            for(int j = y; j < y + 3; j++)
                if(board[i][j] == num + '0')
                    return false;
        return true;
    }

    bool solve(vector<vector<char>>& board, int x, int y){
        while(x < 9 && board[x][y] != '.'){
            y++;
            if(y == 9){
                x++;
                y = 0;
            }
        }
        if(x == 9)
            return true;
        for(int i = 1; i <= 9; i++){
            if(isSafe(x, y, board, i)){
                board[x][y] = i + '0';
                if(solve(board, x, y))
                    return true;
                board[x][y] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
