class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m;

        while(l <= r){
            m = (l + r) / 2;
            if(r == 1)  return (nums[0] > nums[1] ? 0 : 1);
            else if(m == 0 || m == n - 1)    return m;
            else if(nums[m - 1] < nums[m] && nums[m] > nums[m + 1])  return m;
            else if(nums[m - 1] < nums[m] && nums[m] < nums[m + 1])  l = m + 1;
            else r = m - 1;
        }
        return 0;
    }
};
