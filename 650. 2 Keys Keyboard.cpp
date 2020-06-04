class Solution {
public:
    int minSteps(int n) {
        int dp[n + 1];

        dp[1] = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = INT_MAX;
            for(int j = i - 1; j > 0; j--)
                if(i % j == 0)  dp[i] = min(dp[i], dp[j] + i / j);
        }
        return dp[n];
    }
};

/////////////////////////////////////

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int i = 2;

        while(n > 1){
            while(n % i == 0){
                res += i;
                n /= i;
            }
            i++;
        }
        return res;
    }
};
