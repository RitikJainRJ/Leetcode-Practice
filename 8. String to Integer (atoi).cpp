#define ll unsigned long long

class Solution {
public:
    int myAtoi(string s) {
        ll res = 0, n = s.length(), sign = 1;

        int i = 0;
        while(i < n && s[i] == ' ')
            i++;
        if(i < n && s[i] == '+')
            sign = 1, i++;
        else if(i < n && s[i] == '-')
            sign = -1, i++;
        while(i < n && '0' <= s[i] && s[i] <= '9'){
            res = res * 10 + (s[i] - '0');
            i++;
            if(res > INT_MAX)
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return (int)res * sign;
    }
};
