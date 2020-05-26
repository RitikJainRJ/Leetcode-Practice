class Solution {
private:
    bool partition(vector<int> &nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
            if(dp[i][sum])
                return true;
        }
        return false;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i];
        if(sum % 2 != 0)
            return false;
        return partition(nums, sum / 2);
    }
};
