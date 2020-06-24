class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int hash_s[256] = {0}, hash_p[256] = {0};

        for(int i = 0; i < p.length(); i++)
            hash_p[p[i]]++;
        int i = 0, j, count = 0;
        for(j = 0; j < s.length(); j++){
            hash_s[s[j]]++;

            if(hash_p[s[j]] != 0 && hash_s[s[j]] <= hash_p[s[j]])
                count++;
            if(count == p.length()){
                while(hash_p[s[i]] == 0 || hash_s[s[i]] > hash_p[s[i]]){
                    hash_s[s[i]]--;
                    i++;
                }
                if(j - i + 1 == p.length())
                    res.push_back(i);
            }
        }
        return res;
    }
};
