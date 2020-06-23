class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        color[0] = 0;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i = 0; i < graph[u].size(); i++){
                if(color[graph[u][i]] == -1){
                    color[graph[u][i]] = !color[u];
                    q.push(graph[u][i]);
                }
                else if(color[graph[u][i]] == color[u])
                    return false;
            }
            if(q.empty()){
                for(int i = 0; i < n; i++)
                    if(color[i] == -1){
                        color[i] = 0;
                        q.push(i);
                        break;
                    }
            }
        }
        return true;
    }
};
