class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1, right = 1;

        for(int i = 1; i < n; i++){
            res[i] *= left * nums[i - 1];
            left = left * nums[i - 1];
            res[n - i - 1] *= right * nums[n - i];
            right = right * nums[n - i];
        }
        return res;
    }
};
