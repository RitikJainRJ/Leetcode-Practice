class Solution {
private:
    void _permute(int ind, vector<int>& nums, vector<vector<int>>& res){
        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++){
            swap(nums[i], nums[ind]);
            _permute(ind + 1, nums, res);
            swap(nums[i], nums[ind]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        _permute(0, nums, res);
        return res;
    }
};
