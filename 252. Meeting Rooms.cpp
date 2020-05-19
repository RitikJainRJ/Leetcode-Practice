#include<bits/stdc++.h>
using namespace std;

bool canAttendMettings(vector<vector<int>>&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> inter;

        for(int i = 0; i < n; i++){
            int s, e;
            cin >> s >> e;
            inter.push_back({s, e});
        }
        cout << canAttendMettings(inter) << endl;
    }
    return 0;
}

bool canAttendMettings(vector<vector<int>> &inter){
    int n = inter.size();

    sort(inter.begin(), inter.end());
    for(int i = 1; i < n; i++)
        if(inter[i - 1][1] > inter[i][0])
            return false;
    return true;
}
