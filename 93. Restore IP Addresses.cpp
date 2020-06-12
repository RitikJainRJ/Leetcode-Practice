class Solution {
private:
    void solve(string &s, int ind, int c, string ans, vector<string> &res){
        if(c == 4){
            if(ans.length() == s.length() + 4){
                ans.pop_back();
                res.push_back(ans);
            }
            return;
        }
        for(int i = 1; i <= 3 && ind + i <= s.length(); i++){
            string temp = s.substr(ind, i);
            int a = stoi(temp);
            if(temp.size() == 1 || (temp[0] != '0' && 0 <= a && a <= 255))
                solve(s, ind + i, c + 1, ans + temp + ".", res);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        solve(s, 0, 0, "", res);
        return res;
    }
};
