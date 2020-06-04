class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j;
        int n = nums.size();

        for(j = 0; j < n; j++){
            if((j + 1 < n && nums[j] == nums[j + 1]) && (j - 1 >= 0 && nums[j] == nums[j - 1]))
                continue;
            nums[i++] = nums[j];
        }
        return i;
    }
};
