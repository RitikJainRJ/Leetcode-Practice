class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0, r = n, m;

        while(l <= r && n > l){
            m = (l + min(r, n)) / 2;

            if(nums[m] < nums[n])
                r = m - 1;
            else if(nums[m] > nums[n])
                l = m + 1;
            else
                n--;
        }
        return nums[l];
    }
};
