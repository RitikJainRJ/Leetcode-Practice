class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> um;
        int n = S.length();

        for(int i = 0; i < n; i++)
            um[S[i]] = i;
        int i = 0, j, k;
        for(j = 0; j < n; j++){
            k = 0;
            do{
                k = max(k, um[S[j]]);
                j++;
            }while(j <= k);
            res.push_back(j - i);
            i = j;
            j--;
        }
        return res;
    }
};
