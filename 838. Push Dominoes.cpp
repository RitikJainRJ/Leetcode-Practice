class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        vector<int> left(n, INT_MAX), right(n, INT_MAX);

        for(int i = 0; i < n; i++)
            if(s[i] == 'R'){
                int j = i + 1, count = 0;
                while(j < n && s[j] == '.')
                    right[j++] = count++;
                i = j - 1;
            }
        for(int i = n - 1; i >= 0; i--)
            if(s[i] == 'L'){
                int j = i - 1, count = 0;
                while(j >= 0 && s[j] == '.')
                    left[j--] = count++;
                i = j + 1;
            }
        for(int i = 0; i < n; i++)
            if(s[i] == '.'){
                if(left[i] < right[i])  s[i] = 'L';
                else if(right[i] < left[i]) s[i] = 'R';
            }
        return s;
    }
};
