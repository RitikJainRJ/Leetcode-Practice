class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            if(nums[l] > 0)
                l++;
            else if(nums[r] <= 0)
                r--;
            else{
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        for(int i = 0; i < l; i++){
            int x = abs(nums[i]) - 1;
            if(x < l)
                nums[x] = abs(nums[x]) * -1;
        }
        int i;
        for(i = 0; i < l; i++)
            if(nums[i] > 0)
                break;
        return i + 1;
    }
};
