class Solution {
private:
    int pivot(vector<int>& nums){
        int l = 0, r = nums.size() - 1, m;

        while(l <= r){
            m = (l + r) / 2;

            if(nums[0] <= nums[m])
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }

    int binary_search(int l, int r, vector<int>& nums, int target){
        int m;

        while(l <= r){
            m = (l + r) / 2;

            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int p = pivot(nums);

        int a = binary_search(0, p, nums, target);
        int b = binary_search(p + 1, nums.size() - 1, nums, target);
        return a != -1 ? a : b;
    }
};
