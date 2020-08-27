class Solution {
private:
    int crossProduct(vector<int> &u, vector<int> &v, vector<int> &x){
        int res = (u[0] - v[0]) * (u[1] - x[1]) - (u[1] - v[1]) * (u[0] - x[0]);
        if(res == 0)
            return 0;
        return res > 0 ? 1 : -1;
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int>> res;
        set<vector<int>> os;
        int n = points.size();
        int s, u, v;

        s = 0;
        for(int i = 1; i < n; i++)
            if(points[s][0] > points[i][0])
                s = i;
        u = s;
        do{
            os.insert(points[u]);
            v = (u + 1) % n;
            for(int i = 0; i < n; i++)
                if(i != u && crossProduct(points[u], points[v], points[i]) > 0)
                    v = i;
            for(int i = 0; i < n; i++)
                if(i != v && i != u && crossProduct(points[u], points[v], points[i]) == 0)
                    os.insert(points[i]);
            u = v;
        }while(s != u);
        for(auto it = os.begin(); it != os.end(); it++)
            res.push_back(*it);
        return res;
    }
};
