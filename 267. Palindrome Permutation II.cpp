class Solution {
private:
    void permute(int i, string &s, char extra, vector<string>& res){
        if(i == s.length()){
            string temp = s;
            reverse(temp.begin(), temp.end());
            if(extra != '$')
                res.push_back(s + extra + temp);
            else
                res.push_back(s + temp);
        }
        unordered_set<int> us;
        for(int j = i; j < s.length(); j++){
            if(us.find(s[j]) == us.end()){
                us.insert(s[j]);
                swap(s[i], s[j]);
                permute(i + 1, s, extra, res);
                swap(s[i], s[j]);
            }
        }
    }

public:
    vector<string> generatePalindromes(string &s) {
        vector<string> res;
        unordered_map<char, int> um;
        string word;
        bool is2Odd = false;
        char extra = '$';

        for(int i = 0; i < s.length(); i++)
            um[s[i]]++;
        for(auto it = um.begin(); it != um.end(); it++){
            if(it->second % 2 != 0 && is2Odd)
                return res;
            else if(it->second % 2 != 0)
                is2Odd = true;
            int k = it->second / 2;
            while(k--)
                word += it->first;
            if(it->second % 2 != 0)
                extra = it->first;
        }
        permute(0, word, extra, res);
        return res;
    }
};
