class Solution {
public:
    int minSwapsCouples(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> um;

        for(int i = 0; i < n; i++)
            um[nums[i]] = i;
        for(int i = 0; i < n; i += 2){
            int x;
            if(nums[i] % 2 == 0)
                x = nums[i] + 1;
            else
                x = nums[i] - 1;
            if(nums[i + 1] == x)
                continue;
            res++;
            um[nums[i + 1]] = um[x];
            swap(nums[i + 1], nums[um[x]]);
        }
        return res;
    }
};
