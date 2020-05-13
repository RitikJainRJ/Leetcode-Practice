class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(nums[j] == 0 && i != j)
                    swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
