class Solution {
private:
    void solve(int i, vector<int> &nums, int t, vector<int> &ans, vector<vector<int>> &res){
        if(t == 0){
            res.push_back(ans);
            return;
        }
        if(t < 0 || i == nums.size())   return;
        ans.push_back(nums[i]);
        solve(i, nums, t - nums[i], ans, res);
        ans.pop_back();
        solve(i + 1, nums, t, ans, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<vector<int>> res;
        vector<int> ans;

        solve(0, nums, t, ans, res);
        return res;
    }
};
