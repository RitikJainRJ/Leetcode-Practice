class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res1 = 1, res2 = 0;
        int c1 = 0, c2 = 0;

        if(A.size() == 0)
            return 0;
        for(int k = 0; k < A.size() - 1; k++){
            if(k % 2 == 0 && A[k] > A[k + 1])   c1++;
            else if(k % 2 != 0 && A[k] < A[k + 1])  c1++;
            else{
                res1 = max(res1, c1 + 1);
                c1 = 0;
            }
            if(k % 2 == 0 && A[k] < A[k + 1])   c2++;
            else if(k % 2 != 0 && A[k] > A[k + 1])  c2++;
            else{
                res2 = max(res2, c2 + 1);
                c2 = 0;
            }
        }
        res1 = max(res1, c1 + 1);
        res2 = max(res2, c2 + 1);
        return max(res1, res2);
    }
};
