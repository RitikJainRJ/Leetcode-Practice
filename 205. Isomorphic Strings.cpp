class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        int countS = 0, countT = 0;
        unordered_map<char, int> umS, umT;

        if(n1 != n2)
            return false;
        for(int i = 0; i < n1; i++){
            if(umS.find(s[i]) == umS.end())
                umS[s[i]] = countS++;
            if(umT.find(t[i]) == umT.end())
                umT[t[i]] = countT++;
            if(umS[s[i]] != umT[t[i]])
                return false;
        }
        return true;
    }
};
