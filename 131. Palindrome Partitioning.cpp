class Solution {
private:
    void _solve(int ind, string &s, vector<vector<bool>> &dp, vector<string> &ans, vector<vector<string>> &res){
        if(ind == s.length()){
            res.push_back(ans);
            return;
        }
        for(int i = ind; i < s.length(); i++)
            if(dp[ind][i]){
                ans.push_back(s.substr(ind, i - ind + 1));
                _solve(i + 1, s, dp, ans, res);
                ans.pop_back();
            }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));

        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                if(l == 2)
                    dp[i][j] = s[i] == s[j] ? true : false;
                else
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1] ? true : false;
             }
        }
        _solve(0, s, dp, ans, res);
        return res;
    }
};
