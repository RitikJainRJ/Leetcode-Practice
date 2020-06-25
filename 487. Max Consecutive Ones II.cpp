class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int res = 0;

        int i = 0, j, count = 0;
        for(j = 0; j < nums.size(); j++){
            if(nums[j] == 0)
                count++;
            if(count == 2){
                while(nums[i] != 0)
                    i++;
                i++;
                count = 1;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
