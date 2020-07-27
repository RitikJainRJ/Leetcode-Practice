class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> um;
    vector<string> res;

    void dfs(string u){
        while(!um[u].empty()){
            string v = um[u].top();
            um[u].pop();
            dfs(v);
        }
        res.push_back(u);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& edges) {
        for(int i = 0; i < edges.size(); i++)
            um[edges[i][0]].push(edges[i][1]);
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
