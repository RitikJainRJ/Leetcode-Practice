class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int hash[255] = {0}, res = 0;
        int i = 0, j = 0, count = 0;

        for(j = 0; j < s.length(); j++){
            hash[s[j]]++;
            if(hash[s[j]] == 1)
                count++;
            if(count == 3){
                while(hash[s[i]] != 1){
                    hash[s[i]]--;
                    i++;
                }
                hash[s[i]]--;
                i++;
                count--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
