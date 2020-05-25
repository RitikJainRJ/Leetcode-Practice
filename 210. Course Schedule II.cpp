class Graph{
private:
    int n;
    vector<int> *arr;
    int *indegree;

    bool _topological(vector<bool> &visited, vector<int> &res){
        if(res.size() == n)
            return true;
        for(int i = 0; i < n; i++){
            if(visited[i] == false && indegree[i] == 0){
                visited[i] = true;
                res.push_back(i);
                for(int j = 0; j < arr[i].size(); j++)
                    indegree[arr[i][j]]--;
                if(_topological(visited, res))
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

    vector<int> topological(){
        vector<bool> visited(n, false);
        vector<int> res;

        if(_topological(visited, res))
            return res;
        res.clear();
        return res;
    }
};

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m = prereq.size();
        Graph g(n);

        for(int i = 0; i < m; i++)
            g.addEdge(prereq[i][1], prereq[i][0]);
        return g.topological();
    }
};
