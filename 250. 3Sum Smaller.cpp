class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size(), res = 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < target){
                    res += (k - j);
                    j++;
                }
                else
                    k--;
            }
        }
        return res;
    }
};
