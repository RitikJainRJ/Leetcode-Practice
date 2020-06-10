class Solution {
private:
    int kadanes(vector<int>& nums, int a, int b){
        int res = INT_MIN, curr = 0;

        for(int i = a; i < b; i++){
            curr = max(curr + nums[i], nums[i]);
            res = max(res, curr);
        }
        return res;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), sum = 0, sum1, sum2, sum3;

        if(n == 1)
            return nums[0];
        sum1 = kadanes(nums, 0, n);
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i], nums[i] *= -1;
        sum2 = sum + kadanes(nums, 0, n - 1);
        sum3 = sum + kadanes(nums, 1, n);
        return max({sum1, sum2, sum3});
    }
};
