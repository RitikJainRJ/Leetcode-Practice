class Solution {
private:
    int binary_search(vector<int> &nums, int x, int l, int r, int flag){
        int m, res = -1;

        while(l <= r){
            m = (l + r) / 2;
            if(nums[m] == x && flag == 0)
                res = m, r = m - 1;
            else if(nums[m] == x && flag == 1)
                res = m, l = m + 1;
            else if(nums[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return res;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = binary_search(nums, target, 0, nums.size() - 1, 0);
        if(a == -1)   return vector<int>({-1, -1});
        int b = binary_search(nums, target, a, nums.size() - 1, 1);
        return vector<int>({a, b});
    }
};
