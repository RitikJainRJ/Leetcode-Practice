class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int res = 0;

        int i = 0, j;
        for(j = 0; j < s.length(); j++){
            hash[s[j] - 65]++;
            while(j - i + 1 - *max_element(hash.begin(), hash.end()) > k){
                hash[s[i] - 65]--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
