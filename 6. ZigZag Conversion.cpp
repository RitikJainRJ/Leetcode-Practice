class Solution {
public:
    string convert(string s, int n) {
        if(n == 1)  return s;
        int m = s.length();
        unordered_map<int, string> um;
        string res;

        int i = 0, j = 0;
        while(j < m){
            while(i < n && j < m)
                um[i++].push_back(s[j++]);
            i -= 2;
            while(i >= 0 && j < m)
                um[i--].push_back(s[j++]);
            i += 2;
        }
        for(int i = 0; i < n; i++)
            res += um[i];
        return res;
    }
};
