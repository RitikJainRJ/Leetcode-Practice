class Solution {
private:
    int solve(vector<int> &nums, int m){
        int res = 0;

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] >= m)
                res++;
        return res;
    }

public:
    int hIndex(vector<int>& nums){
        int n = nums.size();
        int i = 0, j = INT_MAX, res = 0;

        while(i <= j){
            int m = (i + j) / 2;
            int k = solve(nums, m);

            if(k >= m)
                res = m, i = m + 1;
            else
                j = m - 1;
        }
        return res;
    }
};
