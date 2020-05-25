class Solution {
private:
    int binary_search(int l, int r, int x, vector<int> &dp){
        while(l <= r){
            int mid = (l + r) / 2;
            if(dp[mid] == x)
                return mid;
            else if(dp[mid] < x)
                l = mid + 1;
            else if(dp[mid] > x)
                r = mid - 1;
        }
        return l;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n);

        dp[0] = nums[0];
        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            int index = binary_search(l, r, nums[i], dp);
            dp[index] = nums[i];
            r = max(r, index);
        }
        return r + 1;
    }
};
