class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        unordered_map<int, int> um;
        int curr = 0, res = 0;

        for(int i = 0; i < A.size(); i++){
            curr = (curr + A[i]) % k;
            if(curr < 0)
                curr += k;
            if(curr == 0)
                res++;
            res += um[curr];
            um[curr]++;
        }
        return res;
    }
};
