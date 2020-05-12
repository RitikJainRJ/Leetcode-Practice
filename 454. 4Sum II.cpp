class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> um1, um2;
        int n = A.size(), res = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                um1[A[i] + B[j]]++;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                um2[C[i] + D[j]]++;
        for(auto it = um1.begin(); it != um1.end(); it++){
            if(um2.find(0 - it->first) != um2.end()){
                res = res + (um2[0 - it->first] * it->second);
            }
        }
        return res;
    }
};
