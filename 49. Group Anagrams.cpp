class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> res;

        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            um[temp].push_back(strs[i]);
        }
        for(auto it = um.begin(); it != um.end(); it++)
            res.push_back(it->second);
        return res;
    }
};
