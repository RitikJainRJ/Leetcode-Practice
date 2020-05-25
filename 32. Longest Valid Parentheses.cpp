class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        int n = str.length(), res = 0;

        s.push(-1);
        for(int i = 0; i < n; i++){
            if(str[i] == '(')
                s.push(i);
            else{
                int ind = s.top();
                if(ind == -1 || str[ind] == ')')
                    s.push(i);
                else if(str[ind] == '('){
                    s.pop();
                    res = max(res, i - s.top());
                }
            }
        }
        return res;
    }
};
