#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    void dfs(int u, vvi &graph, vector<bool> &visited, vi &ans, vvi &res){
        if(u == graph.size() - 1){
            ans.push_back(u);
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        visited[u] = true;
        ans.push_back(u);
        for(int i = 0; i < graph[u].size(); i++)
            if(visited[graph[u][i]] == false)
                dfs(graph[u][i], graph, visited, ans, res);
        visited[u] = false;
        ans.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vvi res;
        vi ans;
        int n = graph.size();
        vector<bool> visited(n, false);

        dfs(0, graph, visited, ans, res);
        return res;
    }
};
