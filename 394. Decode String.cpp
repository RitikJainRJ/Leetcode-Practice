class Solution {
public:
    string decodeString(string s) {
        stack<int> s1;
        stack<string> s2;
        string word, res;
        int n = s.length();

        for(int i = 0; i < n; i++){
            if(s[i] == '['){
                s2.push(string(1, '['));
            }
            else if(s[i] == ']'){
                string temp1, temp2;
                int t = s1.top();
                s1.pop();

                while(s2.top() != "["){
                    temp1 = s2.top() + temp1;
                    s2.pop();
                }
                s2.pop();
                while(t--)
                    temp2 += temp1;
                s2.push(temp2);
            }
            else if(isdigit(s[i])){
                while(i < n && '0' <= s[i] && s[i] <= '9')
                    word += s[i++];
                s1.push(stoi(word));
                word = "";
                i--;
            }
            else if(isalpha(s[i])){
                while(i < n && (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')))
                    word += s[i++];
                s2.push(word);
                word = "";
                i--;
            }
        }
        while(!s2.empty()){
            res = s2.top() + res;
            s2.pop();
        }
        return res;
    }
};
