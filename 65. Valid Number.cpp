class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        int countNum = 0, countDot = 0;

        while(s[i] == ' ')  i++;
        if(s[i] == '+' || s[i] == '-')  i++;
        while(isdigit(s[i]) || s[i] == '.')     isdigit(s[i++]) ? countNum++ : countDot++;
        if(countNum < 1 || countDot > 1)    return false;
        if(s[i] == 'e'){
            i++;
            countNum = 0;
            if(s[i] == '+' || s[i] == '-')  i++;
            while(isdigit(s[i]))    i++, countNum++;
            if(countNum < 1)    return false;
        }
        while(s[i] == ' ')  i++;
        return i == n;
    }
};
