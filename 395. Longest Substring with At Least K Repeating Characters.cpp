class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;

        for(int c = 1; c <= 26; c++){
            int hash[26] = {0};

            int i = 0, j, uniquechar = 0, lessthank = 0;
            for(j = 0; j < s.length(); j++){
                hash[s[j] - 'a']++;

                if(hash[s[j] - 'a'] == 1)
                    uniquechar++;
                if(hash[s[j] - 'a'] == k)
                    lessthank++;
                if(uniquechar > c){
                    while(hash[s[i] - 'a'] != 1){
                        if(hash[s[i] - 'a'] == k)
                            lessthank--;
                        hash[s[i] - 'a']--;
                        i++;
                    }
                    hash[s[i] - 'a']--;
                    i++;
                    uniquechar--;
                }
                if(lessthank == c)
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
