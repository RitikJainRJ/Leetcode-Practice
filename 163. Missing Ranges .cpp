class Solution {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();

        if(nums.empty()){
            if(lower != upper)
                res.push_back(to_string(lower) + "->" + to_string(upper));
            else
                res.push_back(to_string(lower));
            return res;
        }
        if(nums[0] != lower){
            if(lower + 1 != nums[0])
                res.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
            else
                res.push_back(to_string(lower));
        }
        for(int i = 1; i < n; i++){
            if(nums[i - 1] == nums[i] || nums[i - 1] + 1 == nums[i])
                continue;
            if(nums[i - 1] != nums[i] - 2)
                res.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
            else
                res.push_back(to_string(nums[i - 1] + 1));
        }
        if(nums[n - 1] != upper){
            if(nums[n - 1] + 1 != upper)
                res.push_back(to_string(nums[n - 1] + 1) + "->" + to_string(upper));
            else
                res.push_back(to_string(upper));
        }
        return res;
    }
};
