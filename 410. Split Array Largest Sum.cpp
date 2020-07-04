#define ll long long
class Solution {
private:
    ll countSubarray(vector<int> &nums, ll total){
        ll sum = 0, res = 1;

        for(ll i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > total){
                res++, sum = nums[i];
            }
        }
        return res;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        ll n = nums.size();
        ll l, r, m, sum = 0, imax = 0, res = 0;

        for(ll i = 0; i < n; i++)
            sum += nums[i], imax = max(imax, (ll)nums[i]);
        l = imax, r = sum;
        while(l <= r){
            m = (l + r) / 2;
            ll c = countSubarray(nums, m);

            if(c <= k)
                res = m, r = m - 1;
            else if(c > k)
                l = m + 1;
        }
        return res;
    }
};
