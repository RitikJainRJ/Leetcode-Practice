class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m;

        while(l <= r){
            m = (l + r) / 2;

            if(nums[m] <= nums[n - 1])
                r = m - 1;
            else
                l = m + 1;
        }
        return nums[l];
    }
};
