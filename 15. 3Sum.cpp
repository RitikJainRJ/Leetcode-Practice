class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int x = 0 - nums[i];
            int l = i + 1, r = n - 1;
            while(l < r){
                if(nums[l] + nums[r] == x){
                    vector<int> temp({nums[i], nums[l], nums[r]});
                    while(l + 1 < n && nums[l] == nums[l + 1])
                        l++;
                    while(r - 1 >= 0 && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                    res.push_back(temp);
                }
                else if(nums[l] + nums[r] < x)
                    l++;
                else if(nums[l] + nums[r] > x)
                    r--;
            }
            while(i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};
