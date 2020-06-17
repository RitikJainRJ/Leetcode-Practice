class Solution {
public:
    string simplifyPath(string s) {
        vector<string> vec;
        string word, res;

        s += "/";
        for(int i = 0; i <= s.length(); i++){
            if(s[i] != '/')
                word += s[i];
            else{
                if(word == ".")
                    word = "";
                else if(word == ".."){
                    if(!vec.empty())
                        vec.pop_back();
                }
                else if(!word.empty())
                    vec.push_back(word);
                word = "";
            }
        }
        for(int i = 0; i < vec.size(); i++)
            res = res + "/" + vec[i];
        if(res.empty())
            return "/";
        return res;
    }
};
