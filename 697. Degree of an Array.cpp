class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> um;
        int n = nums.size(), deg = 0, res = INT_MAX;

        for(int i = 0; i < n; i++){
            um[nums[i]]++;
            deg = max(deg, um[nums[i]]);
        }
        um.clear();

        int i = 0, j;
        for(j = 0; j < n; j++){
            um[nums[j]]++;
            if(um[nums[j]] == deg){
                while(nums[i] != nums[j]){
                    um[nums[i]]--;
                    i++;
                }
                if(res > j - i + 1)
                    res = j - i + 1;
            }
        }
        return res;
    }
};
