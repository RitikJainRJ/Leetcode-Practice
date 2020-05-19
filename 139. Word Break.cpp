class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(dp[j] == true){
                    string temp = s.substr(j, i - j);
                    if(us.find(temp) != us.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
