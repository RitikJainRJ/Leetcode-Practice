class Solution {
public:
    string getPermutation(int n, int k) {
        string s, res;
        int fact[n];

        k--;
        for(int i = 0; i < n; i++)
            s += (i + 1 + '0');
        fact[0] = 1;
        for(int i = 1; i < n; i++)
            fact[i] = i * fact[i - 1];
        for(int i = 1; i <= n; i++){
            int q = k / fact[n - i];
            res += s[q];
            s.erase(q, 1);
            k = k - (q * fact[n - i]);
        }
        return res;
    }
};
