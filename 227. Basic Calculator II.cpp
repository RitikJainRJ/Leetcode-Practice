class Solution {
private:
    int solve(int &a, int &b, char &ch){
        switch(ch){
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
        }
        return -1;
    }
public:
    int calculate(string s) {
        stack<int> s1;
        stack<char> s2;
        int n = s.length(), i = 0, res = 0;
        unordered_map<char, int> um({{'+', 0}, {'-', 0},
                                     {'*', 1}, {'/', 1}});

        while(i < n){
            int x = 0;
            while(s[i] == ' ')
                i++;
            while(isdigit(s[i])){
                x = x * 10 + (s[i] - '0');
                i++;
            }
            s1.push(x);
            while(s[i] == ' ')
                i++;
            if(i == n)
                break;
            while(!s2.empty() && um[s[i]] <= um[s2.top()]){
                int b = s1.top();
                s1.pop();
                int a = s1.top();
                s1.pop();
                res = solve(a, b, s2.top());
                s2.pop();
                s1.push(res);
            }
            s2.push(s[i]);
            i++;
        }
        while(!s2.empty()){
            int b = s1.top();
            s1.pop();
            int a = s1.top();
            s1.pop();
            res = solve(a, b, s2.top());
            s2.pop();
            s1.push(res);
        }
        return s1.top();
    }
};
