class Solution {
private:
    int histogram(vector<int> &nums){
        int n = nums.size(), i = 0, res = 0;
        stack<int> s;

        while(i < n){
            if(s.empty() || nums[s.top()] <= nums[i])
                s.push(i++);
            else{
                int t = s.top();
                s.pop();
                int d = s.empty() ? i : i - s.top() - 1;
                res = max(res, nums[t] * d);
            }
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            int d = s.empty() ? i : i - s.top() - 1;
            res = max(res, nums[t] * d);
        }
        return res;
    }

public:
    int maximalRectangle(vector<vector<char>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0)
            return 0;
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> nums(m, 0);

        for(int i = 0; i < m; i++)
            nums[i] = (mat[0][i] - '0');
        res = histogram(nums);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++)
                nums[j] = (mat[i][j] == '1' ? nums[j] + 1 : 0);
            res = max(res, histogram(nums));
        }
        return res;
    }
};
