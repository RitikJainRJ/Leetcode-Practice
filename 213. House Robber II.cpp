class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);

        int a = nums[0], b = max(nums[0], nums[1]);
        int c1 = b;
        for(int i = 2; i < n - 1; i++){
            c1 = max(b, a + nums[i]);
            a = b;
            b = c1;
        }
        a = nums[1], b = max(nums[1], nums[2]);
        int c2 = b;
        for(int i = 3; i < n; i++){
            c2 = max(b, a + nums[i]);
            a = b;
            b = c2;
        }
        return max(c1, c2);
    }
};
