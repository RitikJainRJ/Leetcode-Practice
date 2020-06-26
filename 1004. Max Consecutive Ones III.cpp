class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;

        int i = 0, j, count = 0;
        for(j = 0; j < n; j++){
            if(nums[j] == 0)
                count++;
            if(count == k + 1){
                while(nums[i] != 0)
                    i++;
                i++;
                count--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
