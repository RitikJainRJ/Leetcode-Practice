class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<int> dist(n, INT_MAX);
        vector<int> temp(n);

        dist[src] = 0;
        for(int i = 0; i <= k; i++){
            temp = dist;
            for(int j = 0; j < m; j++){
                int u = flights[j][0], v = flights[j][1], w = flights[j][2];
                if(dist[u] != INT_MAX && dist[u] + w < temp[v])
                    temp[v] = dist[u] + w;
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
