class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0)   return {};
        int n = mat.size(), m = mat[0].size();
        vector<int> res;

        int i = 0, j = 0;
        while(i < n && j < m){
            while(0 <= i && i < n && 0 <= j && j < m)
                res.push_back(mat[i--][j++]);
            i++;
            if(j == m)
                j--, i++;
            while(0 <= i && i < n && 0 <= j && j < m)
                res.push_back(mat[i++][j--]);
            j++;
            if(i == n)
                i--, j++;
        }
        return res;
    }
};
