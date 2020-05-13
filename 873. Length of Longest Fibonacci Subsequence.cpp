class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> us(A.begin(), A.end());
        int res = 0, n = A.size();
        bool flag = false;

        if(n < 3)
            return res;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int a = A[j], b = A[i], c;
                int temp = 2;

                do{
                    c = a + b;
                    if(us.find(c) != us.end())
                        temp++;
                    else
                        break;
                    flag = true;
                    a = b;
                    b = c;
                }while(1);
                res = max(res, temp);
            }
        }
        if(!flag)
            return 0;
        return res;
    }
};
