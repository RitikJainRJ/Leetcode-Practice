class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> res;
        int n = inter.size();

        if(n == 0)
            return res;
        sort(inter.begin(), inter.end());
        int i = 0, j, m = inter[0][1];
        for(j = 0; j < n; j++){
            if(inter[j][0] <= m){
                m = max(m, inter[j][1]);
            }
            else{
                res.push_back({inter[i][0], m});
                i = j;
                m = inter[j][1];
            }
        }
        res.push_back({inter[i][0], m});
        return res;
    }
};
