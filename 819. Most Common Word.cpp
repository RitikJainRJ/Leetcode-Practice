class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        unordered_map<string, int> um;
        unordered_set<string> us(banned.begin(), banned.end());
        int max = 0;
        string res;

        int i = 0, j;
        para = para + '.';
        for(j = 0; j < para.length(); j++){
            if(('a' <= para[j] && para[j] <= 'z') || ('A' <= para[j] && para[j] <= 'Z'))
                continue;
            else{
                string temp = para.substr(i, j - i);
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                i = j + 1;
                if(!temp.empty())
                    um[temp]++;
            }
        }
        for(auto it = um.begin(); it != um.end(); it++)
            cout << it->first << " " << it->second << endl;
        for(auto it = um.begin(); it != um.end(); it++)
            if(it->second > max && us.find(it->first) == us.end()){
                max = it->second;
                res = it->first;
            }
        return res;
    }
};
