class Solution {
    int binary_search(int l, int r, int x, vector<int>& nums){
        int m;

        while(l <= r){
            m = (l + r) / 2;

            if(nums[m] > x)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;

        for(i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]){
                int ind = binary_search(i, n - 1, nums[i - 1], nums);
                swap(nums[i - 1], nums[ind]);
                sort(nums.begin() + i, nums.end());
                break;
            }
        }
        if(i == 0)
            sort(nums.begin(), nums.end());
    }
};
