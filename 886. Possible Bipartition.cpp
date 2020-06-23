class Graph{
private:
    int n;
    vector<int> *arr;

public:
    Graph(int n, vector<vector<int>> &edges){
        this->n = n;
        arr = new vector<int>[n];

        for(int i = 0; i < edges.size(); i++){
            arr[edges[i][0] - 1].push_back(edges[i][1] - 1);
            arr[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
    }

    bool isBipartite(){
        vector<int> color(n, -1);
        queue<int> q;

        color[0] = 0;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i = 0; i < arr[u].size(); i++)
                if(color[arr[u][i]] == -1)
                    color[arr[u][i]] = !color[u], q.push(arr[u][i]);
                else if(color[arr[u][i]] == color[u])
                    return false;
            if(q.empty())
                for(int i = 0; i < n; i++)
                    if(color[i] == -1){
                        color[i] = 0;
                        q.push(i);
                        break;
                    }
        }
        return true;
    }

};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        Graph g(n, dislikes);
        return g.isBipartite();
    }
};
