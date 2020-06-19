class Solution {
private:
    int find(int num, vector<int>& parent){
        if(parent[num] == -1)
            return num;
        return find(parent[num], parent);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, -1);

        for(int i = 0; i < n; i++){
            int a = find(edges[i][0], parent);
            int b = find(edges[i][1], parent);

            if(a == b)
                return edges[i];
            parent[b] = a;
        }
        return edges[0];
    }
};
