class Solution {
public:
    int minCostII(vector<vector<int>> &costs) {
        if(costs.size() == 0 || costs[0].size() == 0)
            return 0;
        int n = costs.size(), k = costs[0].size();

        for(int i = 1; i < n; i++){
            int lmin[k], rmin[k];

            lmin[0] = INT_MAX, rmin[k - 1] = INT_MAX;
            for(int j = 1; j < k; j++){
                lmin[j] = min(costs[i - 1][j - 1], lmin[j - 1]);
                rmin[k - 1 - j] = min(costs[i - 1][k - j], rmin[k - j]);
            }
            for(int j = 0; j < k; j++)
                costs[i][j] += min(lmin[j], rmin[j]);
        }
        return *min_element(costs[n - 1].begin(), costs[n - 1].end());
    }
};
