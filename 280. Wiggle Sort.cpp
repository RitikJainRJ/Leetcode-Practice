#include<bits/stdc++.h>
using namespace std;

void wiggleSort(vector<int>&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        vector<int> vec;

        cin >> n;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            vec.push_back(a);
        }
        wiggleSort(vec);
        for(int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}

void wiggleSort(vector<int> &nums){
    int n = nums.size();

    for(int i = 0; i < n - 1; i++){
        if((i % 2 == 0 && nums[i] > nums[i + 1]) || (i % 2 != 0 && nums[i] < nums[i + 1])){
            swap(nums[i], nums[i + 1]);
        }
    }
}
