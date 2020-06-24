class Solution {
public:

    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        if(words1.size() != words2.size())  return false;
        unordered_multimap<string, string> um;

        for(int i = 0; i < pairs.size(); i++)
            um.insert({pairs[i][0], pairs[i][1]});
        for(int i = 0; i < words1.size(); i++){
            if(words1[i] == words2[i])  continue;
            bool flag = false;
            auto itr = um.equal_range(words1[i]);
            for(auto it = itr.first; it != itr.second; it++)
                if(it->second == words2[i]){
                    flag = true;
                    break;
                }
            if(flag)    continue;
            itr = um.equal_range(words2[i]);
            for(auto it = itr.first; it != itr.second; it++)
                if(it->second == words1[i]){
                    flag = true;
                    break;
                }
            if(flag)    continue;
            else    return false;
        }
        return true;
    }
};
