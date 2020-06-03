class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)  return 0;
        int prod = 1, res = 0;
        int i = 0, j;

        for(j = 0; j < nums.size(); j++){
            prod *= nums[j];
            while(prod >= k)    prod /= nums[i++];
            res += (j - i + 1);
        }
        return res;
    }
};
