class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int i = 1; i < n; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                int a = j + 1 == triangle[i].size() ? INT_MAX : triangle[i - 1][j];
                int b = j == 0 ? INT_MAX : triangle[i - 1][j - 1];
                triangle[i][j] += min(a, b);
            }
        }
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};
