class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || (nums.size() != 1 && nums[0] == 0))
            return false;
        int jump = 1, step = nums[0], max_dis = nums[0];

        for(int i = 1; i < nums.size() - 1; i++){
            step--;
            max_dis = max(max_dis, nums[i] + i);
            if(step == 0){
                jump++;
                step = max_dis - i;
                if(step <= 0)
                    return false;
            }
        }
        return true;
    }
};
