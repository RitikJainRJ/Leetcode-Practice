class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int res = 0;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i], k = 0;
            if(us.find(num - 1) == us.end()){
                while(us.find(num) != us.end()){
                    k++;
                    num++;
                }
                res = max(res, k);
            }
        }
        return res;
    }
};
