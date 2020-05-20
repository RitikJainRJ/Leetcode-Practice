class Solution {
private:
    bool _exist(vector<vector<char>>& board, string word, int ind, int x, int y){
        if(ind == word.length() - 1)
            return true;
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        board[x][y] = '$';
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < board.size() && 0 <= _y && _y < board[_x].size() && board[_x][_y] == word[ind + 1])
                if(_exist(board, word, ind + 1, _x, _y))
                    return true;
        }
        board[x][y] = word[ind];
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == word[0])
                    if(_exist(board, word, 0, i, j))
                        return true;
        return false;;
    }
};
