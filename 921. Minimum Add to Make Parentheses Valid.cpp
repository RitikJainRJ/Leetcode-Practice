class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;

        for(int i = 0; i < S.size(); i++){
            if(s.empty())   s.push(S[i]);
            else if(S[i] == ')' && s.top() == '(')  s.pop();
            else    s.push(S[i]);
        }
        return s.size();
    }
};
