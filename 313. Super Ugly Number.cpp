class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0);
        vector<int> nums(n);

        nums[0] = 1;
        for(int i = 1; i < n; i++){
            int ind, min = INT_MAX;
            for(int j = 0; j < primes.size(); j++){
                if(min > primes[j] * nums[index[j]]){
                    min = primes[j] * nums[index[j]];
                    ind = j;
                }
            }
            nums[i] = min;
            index[ind]++;
            if(nums[i] == nums[i - 1])
                i--;
        }
        for(int i = 0; i < n; i++)
            cout << nums[i] << " ";
        return nums[n - 1];
    }
};
