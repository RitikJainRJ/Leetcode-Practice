class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> res;
        int n = words.size();
        if(n == 0)
            return res;
        int l = words[0].size();
        unordered_map<string, int> um1, um2;

        for(int i = 0; i < n; i++)
            um1[words[i]]++;
        for(int i = 0; i <= s.length() - (n * l) + 1; i++){
            int count = 0;
            um2 = um1;
            for(int j = i; j < s.length(); j = j + l){
                string temp = s.substr(j, l);
                if(um2.find(temp) != um2.end() && um2[temp] != 0){
                    um2[temp]--;
                    count++;
                }
                else
                    break;
            }
            if(count == n)
                res.push_back(i);
        }
        return res;
    }
};
