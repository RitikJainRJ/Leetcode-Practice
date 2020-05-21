class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int count = 1;

        int rb = 0, re = n - 1, cb = 0, ce = n - 1;
        while(1){
            if(cb > ce)
                break;
            for(int j = cb; j <= ce; j++)
                matrix[rb][j] = count++;
            rb++;
            if(rb > re)
                break;
            for(int i = rb; i <= re; i++)
                matrix[i][ce] = count++;
            ce--;
            if(cb > ce)
                break;
            for(int j = ce; j >= cb; j--)
                matrix[re][j] = count++;
            re--;
            if(rb > re)
                break;
            for(int i = re; i >= rb; i--)
                matrix[i][cb] = count++;
            cb++;
        }
        return matrix;
    }
};
