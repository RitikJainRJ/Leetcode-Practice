class Solution {
private:
    int binary_search(string &s, int l, int r, char x){
        int m;

        while(l <= r){
            m = (l + r) / 2;

            if(s[m] > x)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }

public:
    int nextGreaterElement(int N) {
        string s = to_string(N);
        int n = s.length(), i;

        for(i = n - 1; i >= 1; i--){
            if(s[i - 1] < s[i]){
                int ind = binary_search(s, i, n - 1, s[i - 1]);
                cout << ind << " ";
                swap(s[ind], s[i - 1]);
                sort(s.begin() + i, s.end());
                break;
            }
        }
        if(i == 0)
            return -1;
        return stol(s) > INT_MAX ? -1 : stoi(s);
    }
};
