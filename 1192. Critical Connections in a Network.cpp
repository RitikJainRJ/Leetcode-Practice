class Graph{
private:
    int n;
    vector<int> *adj;

    void dfs(int u, int p, vector<bool> &visited, int &time, vector<int> &vis_time, vector<int> &low_time, vector<vector<int>> &res){
        visited[u] = true;

        vis_time[u] = low_time[u] = time++;
        for(auto it = adj[u].begin(); it != adj[u].end(); it++){
            int v = *it;
            if(!visited[v]){
                dfs(v, u, visited, time, vis_time, low_time, res);

                low_time[u] = min(low_time[u], low_time[v]);
                if(vis_time[u] < low_time[v])
                    res.push_back({u, v});
            }
            else if(v != p)
                low_time[u] = min(low_time[u], vis_time[v]);
        }
    }

public:
    Graph(int n){
        this->n = n;
        adj = new vector<int>[n];
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> articulation(){
        vector<vector<int>> res;
        vector<bool> visited(n, false);
        vector<int> vis_time(n), low_time(n);
        int time = 0;

        dfs(0, -1, visited, time, vis_time, low_time, res);
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Graph g(n);
        int e = connections.size();

        for(int i = 0; i < e; i++)
            g.addEdge(connections[i][0], connections[i][1]);
        return g.articulation();
    }
};
