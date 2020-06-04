class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int res = INT_MAX, sum = 0;
        int i = 0, j;

        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            if(sum >= s){
                while(sum - nums[i] >= s){
                    sum -= nums[i];
                    i++;
                }
                res = min(res, j - i + 1);
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};
