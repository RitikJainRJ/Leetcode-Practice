class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length(), n2 = t.length(), m = INT_MAX;
        int hash_t[256] = {0}, hash_s[256] = {0};
        int x = -1, y;
        string res;

        for(int i = 0; i < n2; i++)
            hash_t[t[i]]++;
        int i = 0, j, count = 0;
        for(j = 0; j < n1; j++){
            hash_s[s[j]]++;
            if(hash_t[s[j]] != 0 && hash_s[s[j]] <= hash_t[s[j]])
                count++;
            if(count == n2){
                while(hash_t[s[i]] == 0 || hash_s[s[i]] > hash_t[s[i]]){
                    if(hash_s[s[i]] > hash_t[s[i]])
                        hash_s[s[i]]--;
                    i++;
                }
                int l = j - i + 1;
                if(m > l){
                    m = l;
                    x = i;
                    y = j;
                }
            }
        }
        if(x == -1)
            return "";
        res = s.substr(x, y - x + 1);
        return res;
    }
};
