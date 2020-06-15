class Solution {
private:
    bool isValid(string &s, unordered_map<string, int> &um, int ind){
        int n = s.length();
        bool dp[n + 1];

        if(s.empty())
            return false;
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            dp[i] = false;
            for(int j = i - 1; j >= 0; j--){
                if(dp[j]){
                    string temp = s.substr(j, i - j);
                    if(um.find(temp) != um.end() && um[temp] != ind){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, int> um;
        vector<string> res;

        for(int i = 0; i < words.size(); i++)
            um[words[i]] = i;
        for(int i = 0; i < words.size(); i++)
            if(isValid(words[i], um, i))
                res.push_back(words[i]);
        return res;
    }
};
