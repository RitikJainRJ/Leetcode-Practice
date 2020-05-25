class Graph{
private:
    int n;
    vector<int> *arr;
    int *indegree;

    bool isTopo(vector<bool> &visited, int count){
        if(count == n)
            return true;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0 && visited[i] == false){
                count++;
                visited[i] = true;
                for(int j = 0; j < arr[i].size(); j++)
                    indegree[arr[i][j]]--;
                if(isTopo(visited, count))
                    return true;
            }
        }
        return false;
    }

public:
    Graph(int n){
        this->n = n;
        arr = new vector<int>[n];
        indegree = new int[n];

        for(int i = 0; i < n; i++)
            indegree[i] = 0;
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        indegree[v]++;
    }

    bool topological(){
        vector<bool> visited(n, false);
        return isTopo(visited, 0);
    }
};

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        int m = prereq.size();
        Graph g(n);

        for(int i = 0; i < m; i++)
            g.addEdge(prereq[i][1], prereq[i][0]);
        return g.topological();
    }
};
