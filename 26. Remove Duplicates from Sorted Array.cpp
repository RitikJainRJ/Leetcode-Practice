class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j;

        for(int j = 0; j < nums.size(); j++){
            if(j + 1 < nums.size() && nums[j] == nums[j + 1])
                continue;
            nums[i++] = nums[j];
        }
        return i;
    }
};
