class Solution {
private:
    void computeLPS(vector<int> &lps, string &s){
        int len = 0, i = 1;

        lps[0] = 0;
        while(i < lps.size()){
            if(s[i] == s[len])
                lps[i++] = ++len;
            else{
                if(len == 0)
                    lps[i++] = 0;
                else
                    len = lps[len - 1];
            }
        }
    }

public:
    int strStr(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> lps(m);

        if(m == 0)  return 0;
        computeLPS(lps, p);
        int i = 0, j = 0;
        while(i < n){
            if(s[i] == p[j]){
                i++;
                j++;
            }
            if(j == m)
                return i - m;
            else if(i < n && s[i] != p[j]){
                if(j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }
        return -1;
    }
};
