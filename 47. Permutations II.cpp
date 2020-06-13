class Solution {
private:
    void permute(int i, vector<int> nums, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> us;
        for(int j = i; j < nums.size(); j++){
            if(us.find(nums[j]) == us.end()){
                us.insert(nums[j]);
                swap(nums[i], nums[j]);
                permute(i + 1, nums, res);
                swap(nums[i], nums[j]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;

        permute(0, nums, res);
        return res;
    }
};
