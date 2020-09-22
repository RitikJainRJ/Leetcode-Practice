class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, res;

        for(int i = 0; i < n; i++)
            if(count == 0)  res = nums[i], count = 1;
            else if(res == nums[i]) count++;
            else    count--;
        return res;
    }
};
