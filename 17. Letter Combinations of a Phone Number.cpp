class Solution {
private:
    void _comb(int ind, string ans, string digits, vector<string> &res, unordered_map<int, string> &um){
        if(ind == digits.length()){
            res.push_back(ans);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < um[digit].size(); i++)
            _comb(ind + 1, ans + um[digit][i], digits, res, um);
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<int, string> um;

        if(digits.empty())
            return res;
        um[2] = "abc";
        um[3] = "def";
        um[4] = "ghi";
        um[5] = "jkl";
        um[6] = "mno";
        um[7] = "pqrs";
        um[8] = "tuv";
        um[9] = "wxyz";
        _comb(0, "", digits, res, um);
        return res;
    }
};
