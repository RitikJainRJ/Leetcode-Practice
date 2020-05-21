class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return res;

        int m = matrix.size(), n = matrix[0].size();
        int rb = 0, re = m - 1, cb = 0, ce = n - 1;
        while(rb <= re && cb <= ce){
            for(int j = cb; j <= ce; j++)
                res.push_back(matrix[rb][j]);
            rb++;
            for(int i = rb; i <= re; i++)
                res.push_back(matrix[i][ce]);
            ce--;
            if(rb > re)
                break;
            for(int j = ce; j >= cb; j--)
                res.push_back(matrix[re][j]);
            re--;
            if(cb > ce)
                break;
            for(int i = re; i >= rb; i--)
                res.push_back(matrix[i][cb]);
            cb++;
        }
        return res;
    }
};
