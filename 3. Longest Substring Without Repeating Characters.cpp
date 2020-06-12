class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash_s[256] = {0}, res = 0;

        int i = 0, j;
        for(j = 0; j < s.length(); j++){
            hash_s[s[j]]++;
            if(hash_s[s[j]] != 1){
                while(s[i] != s[j]){
                    hash_s[s[i]]--;
                    i++;
                }
                hash_s[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
