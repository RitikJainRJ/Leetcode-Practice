class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        if(mat.size() == 0 || mat[0].size() == 0)
            return false;
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1;

        while(i < n && j >= 0){
            if(mat[i][j] == x)
                return true;
            else if(mat[i][j] > x)
                j--;
            else
                i++;
        }
        return false;
    }
};
