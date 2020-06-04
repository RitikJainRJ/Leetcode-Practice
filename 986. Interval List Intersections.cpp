class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> res;
        int n1 = A.size(), n2 = B.size();
        int i = 0, j = 0;

        while(i < n1 && j < n2){
            int a = max(A[i][0], B[j][0]), b = min(A[i][1], B[j][1]);
            if(a <= b)   res.push_back(vector<int>({a, b}));
            if(A[i][1] < B[j][1])   i++;
            else    j++;
        }
        return res;
    }
};
