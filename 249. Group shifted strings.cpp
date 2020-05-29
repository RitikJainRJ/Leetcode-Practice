/*
1
9
acd dfg wyz yab mop bdfh a x moqs
*/
#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>&);
string convert(string&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<string> strs(n);

        for(int i = 0; i < n; i++)
            cin >> strs[i];
        solve(strs);
    }
    return 0;
}

void solve(vector<string> &strs){
    int n = strs.size();
    unordered_map<string, vector<string>> um;

    for(int i = 0; i < n; i++){
        string temp = convert(strs[i]);
        um[temp].push_back(strs[i]);
    }
    for(auto it = um.begin(); it != um.end(); it++){
        for(int i = 0; i < it->second.size(); i++)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

string convert(string &s){
    string res;
    for(int i = 1; i < s.length(); i++){
        int d;
        if(s[i] >= s[i - 1])
            d = s[i] - s[i - 1];
        else
            d = s[i] - s[i - 1] + 26;
        char ch = d + 97;
        res += ch;
    }
    return res;
}
