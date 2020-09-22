class Graph{
private:
    unordered_map<char, vector<char>> um;

    bool dfs(char u, unordered_set<char> &visited, unordered_set<char> &rec, stack<char> &s){
        visited.insert(u);
        rec.insert(u);

        for(auto it = um[u].begin(); it != um[u].end(); it++)
            if(visited.find(*it) == visited.end()){
                if(dfs(*it, visited, rec, s))
                    return true;
            }
            else if(rec.find(*it) != rec.end())
                return true;
        rec.erase(u);
        s.push(u);
        return false;
    }

public:
    void addEdge(char u, char v){
        um[u].push_back(v);
    }

    string solve(unordered_set<char> &all_chars){
        vector<char> vec;
        unordered_set<char> visited, rec;
        stack<char> s;
        string res;

        for(auto it = um.begin(); it != um.end(); it++)
            vec.push_back(it->first);
        for(int i = 0; i < vec.size(); i++)
            if(visited.find(vec[i]) == visited.end() && dfs(vec[i], visited, rec, s))
                return "";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        for(auto it = all_chars.begin(); it != all_chars.end(); it++)
            if(visited.find(*it) == visited.end())
                res.insert(lower_bound(res.begin(), res.end(), *it), *it);
        return res;
    }
};


class Solution {
public:
    string alienOrder(vector<string> &words) {
        int n = words.size();
        unordered_set<char> us;
        Graph g;
        bool flag;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < words[i].size(); j++)
                us.insert(words[i][j]);
        for(int i = 1; i < n; i++){
            flag = false;
            for(int j = 0; j < min(words[i - 1].length(), words[i].length()); j++)
                if(words[i - 1][j] != words[i][j]){
                    g.addEdge(words[i - 1][j], words[i][j]);
                    flag = true;
                    break;
                }
            if(!flag && words[i - 1].length() > words[i].length())
                return "";
        }
        return g.solve(us);
    }
};
