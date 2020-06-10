class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int res = 0, end;

        if(inter.size() == 0)
            return 0;
        sort(inter.begin(), inter.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        end = inter[0][1];
        for(int i = 1; i < inter.size(); i++){
            if(inter[i][0] < end)
                res++;
            else
                end = inter[i][1];
        }
        return res;
    }
};
