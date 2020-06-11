class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 0;

        if(points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int i = 0, j;
        for(int j = 1; j < points.size(); j++){
            if(points[j][0] <= points[i][1])
                continue;
            res++;
            i = j;
        }
        return res + 1;
    }
};
