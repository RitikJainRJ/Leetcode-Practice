class Solution {
private:
    bool binary_search(vector<int> &nums, int x){
        int l = 0, r = nums.size() - 1, m;

        while(l <= r){
            m = (l + r) / 2;

            if(nums[m] == x)
                return true;
            else if(nums[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        if(mat.size() == 0 || mat[0].size() == 0)
            return false;
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = n - 1, mid;

        if(x < mat[0][0] || x > mat[n - 1][m - 1])
            return false;
        while(l <= r){
            mid = (l + r) / 2;
            if(mat[mid][0] == x)
                return true;
            else if(mat[mid][0] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return binary_search(mat[r], x);
    }
};
