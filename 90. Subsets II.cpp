class Solution {
private:
    void solve(vector<int> &nums, int i, vector<int> &ans, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        solve(nums, i + 1, ans, res);
        ans.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        solve(nums, i + 1, ans, res);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;

        sort(nums.begin(), nums.end());
        if(nums.empty())    return res;
        solve(nums, 0, ans, res);
        return res;
    }
};
