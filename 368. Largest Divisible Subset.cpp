#define pii pair<int, int>

class Solution {
private:
    void solve(int i, vector<int> &nums, vector<pii> &dp, vector<int> &res){
        if(i == dp[i].first){
            res.push_back(nums[i]);
        }
        else{
            res.push_back(nums[i]);
            solve(dp[i].first, nums, dp, res);
        }
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), max = INT_MIN, ind;
        vector<int> res;
        vector<pii> dp(n);
        if(nums.empty())    return res;

        sort(nums.begin(), nums.end());
        dp[0] = {0, 1};
        for(int i = 1; i < n; i++){
            dp[i] = {i, 1};
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0 && 1 + dp[j].second > dp[i].second){
                    dp[i] = {j, 1 + dp[j].second};
                }
            }
            if(max < dp[i].second){
                max = dp[i].second;
                ind = i;
            }
        }
        cout << max ;
        solve(ind, nums, dp, res);
        return res;
    }
};
