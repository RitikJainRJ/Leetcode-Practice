class Solution {
public:
    bool canPermutePalindrome(string &s) {
        unordered_map<char, int> um;
        bool is2Odd = false;

        for(int i = 0; i < s.length(); i++)
            um[s[i]]++;
        for(auto it = um.begin(); it != um.end(); it++)
            if(it->second % 2 != 0 && is2Odd)
                return false;
            else if(it->second % 2 != 0)
                is2Odd = true;
        return true;
    }
};
