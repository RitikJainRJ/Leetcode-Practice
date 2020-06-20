class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        if(s == t)
            return 0;
        unordered_map<int, vector<int>> um;
        unordered_set<int> us;
        queue<vector<int>> q;
        int l = 0;

        for(int i = 0; i < routes.size(); i++)
            for(int j = 0; j < routes[i].size(); j++)
                um[routes[i][j]].push_back(i);

        for(auto it = um[s].begin(); it != um[s].end(); it++)
            q.push(routes[*it]), us.insert(*it);
        while(!q.empty()){
            int size = q.size();
            l++;

            while(size--){
                vector<int> f = q.front();
                q.pop();

                for(int i = 0; i < f.size(); i++){
                    if(f[i] == t)
                        return l;

                    for(auto it = um[f[i]].begin(); it != um[f[i]].end(); it++)
                        if(us.find(*it) == us.end())
                            q.push(routes[*it]), us.insert(*it);
                }
            }
        }
        return -1;
    }
};
