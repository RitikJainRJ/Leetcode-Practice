#include<bits/stdc++.h>
using namespace std;

string checkPre(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << checkPre(n) << endl;
    }
    return 0;
}

string checkPre(int n){
    stack<int> s;
    int lim = INT_MIN, arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0;
    while(i < n){
        if(arr[i] < lim)
            return "false";
        if(s.empty() || s.top() >= arr[i]){
            s.push(arr[i]);
            i++;
        }
        else{
            lim = s.top();
            s.pop();
        }
    }
    return "true";
}
