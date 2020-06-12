class Solution {
private:
    int binary_search(int l, int r, int x, vector<int>& nums){
        int m;

        while(l <= r){
            m = (l + r) / 2;

            if(nums[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }

public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        int n = nums.size();

        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] > nums[i]){
                int idx = binary_search(i, n - 1, nums[i - 1], nums);
                while(idx - 1 >= 0 && nums[idx] == nums[idx - 1])
                    idx--;
                swap(nums[i - 1], nums[idx]);
                break;
            }
        }
        return nums;
    }
};
