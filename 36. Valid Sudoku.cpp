class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used1[9][9] = {false}, used2[9][9] = {false}, used3[9][9] = {false};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int temp = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;;
                    if(used1[i][temp] || used2[j][temp] || used3[k][temp])
                        return false;
                    used1[i][temp] = used2[j][temp] = used3[k][temp] = true;
                }
            }
        }
        return true;
    }
};
