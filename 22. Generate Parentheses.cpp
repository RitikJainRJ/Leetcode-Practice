class Solution {
private:
    void _genePara(int ob, int cb, int n, string ans, vector<string> &res){
        if(ans.length() == 2 * n){
            res.push_back(ans);
            return;
        }
        if(ob < n)
            _genePara(ob + 1, cb, n, ans + '(', res);
        if(ob > cb)
            _genePara(ob, cb + 1, n, ans + ')', res);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        _genePara(0, 0, n, "", res);
        return res;
    }
};
