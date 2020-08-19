class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        string pat;

        sort(products.begin(), products.end());
        for(int i = 0; i < searchWord.length(); i++){
            vector<string> ans;
            pat += searchWord[i];
            auto it = lower_bound(products.begin(), products.end(), pat);
            for(int i = 0; i < 3 && it + i != products.end(); i++){
                string &s = *(it + i);
                if(pat != s.substr(0, pat.length()))  break;
                ans.push_back(s);
            }
            res.push_back(ans);
        }
        return res;
    }
};
