class Solution {
public:
    string solveEquation(string s) {
        int x = 0, num = 0;
        bool flag = false;
        string word;

        s += '+';
        for(int i = 0; i <= s.length(); i++){
            if(s[i] != '+' && s[i] != '-' && s[i] != '='){
                word += s[i];
            }
            else if(word.empty())
                word += s[i];
            else{
                int t;
                if(word.back() == 'x'){
                    word.pop_back();
                    if(word.empty())    t = 1;
                    else if(word.size() == 1 && (word[0] == '+' || word[0] == '-'))   t = (word[0] == '+' ? 1 : -1);
                    else    t = stoi(word);
                    if(!flag)   x += t;
                    else    x -= t;
                }
                else{
                    t = stoi(word);
                    if(!flag)   num += t;
                    else    num -= t;
                }
                word = s[i];
                if(word == "=")
                    flag = true, word = "";
            }
        }
        if(x == 0 && num == 0)
            return "Infinite solutions";
        else if(x == 0)
            return "No solution";
        else
            return "x=" + to_string((num / x) * -1);
    }
};
