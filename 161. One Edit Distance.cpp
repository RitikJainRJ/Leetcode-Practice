class Solution {
public:
    bool isOneEditDistance(string &s, string &t) {
        int n1 = s.length(), n2 = t.length();
        int i = n1 - 1, j = n2 - 1;
        bool flag = false;

        if(s == t || abs(n1 - n2) > 1)
            return false;
        while(i >= 0 && j >= 0){
            if(s[i] == t[j]){
                i--;
                j--;
            }
            else if(s[i] != t[j] && flag){
                return false;
            }
            else if(s[i] != t[j]){
                flag = true;
                if(n1 < n2)
                    j--;
                else if(n1 > n2)
                    i--;
                else{
                    i--;
                    j--;
                }
            }
        }
        return true;
    }
};
