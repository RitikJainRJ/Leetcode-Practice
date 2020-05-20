class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        int n = words.size();
        vector<priority_queue<string, vector<string>, greater<string>>> bucket(n + 1);
        unordered_map<string, int> um;

        for(int i = 0; i < n; i++)
            um[words[i]]++;
        for(auto it = um.begin(); it != um.end(); it++)
            bucket[it->second].push(it->first);
        for(int i = n; i >= 0 && k; i--){
            while(!bucket[i].empty() && k){
                res.push_back(bucket[i].top());
                bucket[i].pop();
                k--;
            }
        }
        return res;
    }
};
