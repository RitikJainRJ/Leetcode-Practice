class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int jump = 1, step = nums[0], max_dis = nums[0];

        for(int i = 1; i < nums.size() - 1; i++){
            step--;
            max_dis = max(max_dis, nums[i] + i);
            if(step == 0){
                jump++;
                step = max_dis - i;
            }
        }
        return jump;
    }
};
