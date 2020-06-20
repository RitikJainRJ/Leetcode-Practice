class Graph{
private:
    int n;
    vector<vector<int>> graph;

    int minDist(vector<int>& dist, vector<bool> &sptSet){
        int m = INT_MAX, res = 0;

        for(int i = 0; i < n; i++)
            if(!sptSet[i] && m > dist[i])
                m = dist[i], res = i;
        return res;
    }

public:
    Graph(int n, vector<vector<int>> &graph){
        this->n = n;
        this->graph = graph;
    }

    int dijkstras(int s){
        vector<bool> sptSet(n, false);
        vector<int> dist(n, INT_MAX);
        int res;

        dist[s] = 0;
        for(int i = 0; i < n - 1; i++){
            int u = minDist(dist, sptSet);
            sptSet[u] = true;

            for(int v = 0; v < n; v++)
                if(graph[u][v] != INT_MAX && !sptSet[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
        res = *max_element(dist.begin(), dist.end());
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < times.size(); i++)
            graph[times[i][0] - 1][times[i][1] - 1] = times[i][2];
        Graph g(n, graph);
        return g.dijkstras(k - 1);
    }
};
