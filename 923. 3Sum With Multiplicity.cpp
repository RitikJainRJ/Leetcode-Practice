#define MAX 1000000007
#define ll unsigned long long

class Solution {
public:
    int threeSumMulti(vector<int>& nums, int t) {
        ll n = nums.size(), res = 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == t){
                    if(nums[j] == nums[k]){
                        int temp = k - j;
                        res += ((temp * (temp + 1)) / 2);
                        break;
                    }
                    int c1 = 1, c2 = 1;
                    while(j + 1 < k && nums[j] == nums[j + 1])
                        j++, c1++;
                    while(j + 1 < k && nums[k] == nums[k - 1])
                        k--, c2++;
                    j++;
                    k--;
                    res += ((c1 * c2));
                }
                else if(sum < t)
                    j++;
                else
                    k--;
            }
        }
        return res % MAX;
    }
};
