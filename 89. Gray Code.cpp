class Solution {
private:
    int btoi(string &s){
        int res = 0, p = 1;

        for(int i = s.length() - 1; i >= 0; i--){
            res += (s[i] - '0') * p;
            p = p * 2;
        }
        return res;
    }

    void solve(vector<string> &ans, int n, vector<int> &res){
        if(n == 1){
            for(int i = 0; i < ans.size(); i++)
                res.push_back(btoi(ans[i]));
            return;
        }
        int l = ans.size();
        for(int i = l - 1; i >= 0; i--)
            ans.push_back(ans[i]);
        for(int i = 0; i < l; i++)
            ans[i] = "0" + ans[i];
        for(int i = l; i < 2 * l; i++)
            ans[i] = "1" + ans[i];
        solve(ans, n - 1, res);
    }

public:
    vector<int> grayCode(int n) {
        vector<int> res;
        vector<string> ans({"0", "1"});
        if(n == 0)   return {0};

        solve(ans, n, res);
        return res;
    }
};
