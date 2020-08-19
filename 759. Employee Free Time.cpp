#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class myComp{
public:
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[0] > b[0];
    }
};

void solve(vector<vector<pii>> &schedule){
    priority_queue<vector<int>, vector<vector<int>>, myComp> pq;
    vector<vector<int>> res;
    int n = schedule.size(), m;

    for(int i = 0; i < n; i++)
        pq.push({schedule[i][0].first, schedule[i][0].second, i, 0});
    m = pq.top()[0];
    while(!pq.empty()){
        vector<int> top = pq.top();
        pq.pop();
        if(m < top[0])
            res.push_back({m, top[0]});
        m = max(m, top[1]);
        if(top[3] + 1 < schedule[top[2]].size()){
            pii &temp = schedule[top[2]][top[3] + 1];
            pq.push({temp.first, temp.second, top[2], top[3] + 1});
        }
    }
    for(int i = 0; i < res.size(); i++)
        cout << "(" << res[i][0] << "," << res[i][1] << ") ";
}

int main(){
    int t, n, m;
    int a, b;

    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<pii>> schedule;

        while(n--){
            cin >> m;
            vector<pii> temp;
            while(m--){
                cin >> a >> b;
                temp.push_back({a, b});
            }
            schedule.push_back(temp);
        }
        solve(schedule);
        cout << endl;
    }
    return 0;
}
