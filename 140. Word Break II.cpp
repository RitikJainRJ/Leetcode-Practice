class Solution {
private:
    void _wordBreak(int ind, vector<vector<string>> &dp, string ans, vector<string> &res){
        if(ind == 0){
            res.push_back(ans);
            return;
        }
        for(int i = 0; i < dp[ind].size(); i++){
            string word = dp[ind][i];
            string updated = word + (ans.empty() ? ans : " " + ans);
            _wordBreak(ind - word.size(), dp, updated, res);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        int n = s.length();
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(n + 1, vector<string>());

        dp[0].push_back(" ");
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(!dp[j].empty() && us.find(s.substr(j, i - j)) != us.end()){
                    dp[i].push_back(s.substr(j, i - j));
                }
            }
        }
        _wordBreak(n, dp, "", res);
        return res;
    }
};
