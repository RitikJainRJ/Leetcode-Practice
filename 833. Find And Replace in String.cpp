class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, string>> bucket(S.length(), {-1, ""});

        for(int i = 0; i < indexes.size(); i++){
            int s = indexes[i];
            int e = s + sources[i].length() - 1;
            int j;
            for(j = s; j <= e; j++){
                if(sources[i][j - s] != S[j])
                    break;
            }
            if(j > e)
                bucket[s] = {sources[i].length(), targets[i]};
        }
        for(int i = S.length() - 1; i >= 0; i--){
            int ind = i;
            int len = bucket[i].first;
            string temp = bucket[i].second;
            if(len == -1)
                continue;
            S.replace(ind, len, temp);
        }
        return S;
    }
};
