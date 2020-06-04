class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        unordered_map<int, int> um;
        int res = 0, curr = 0;

        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            if(curr == k)
                res = max(res, i + 1);
            if(um.find(curr - k) != um.end())
                res = max(res, i - um[curr - k]);
            if(um.find(curr) == um.end())
                um[curr] = i;
        }
        return res;
    }
};
