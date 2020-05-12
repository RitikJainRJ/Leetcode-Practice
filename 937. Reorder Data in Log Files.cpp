bool myComp(string a, string b){
    string i1, i2, A, B;
    for(int i = 0; i < a.length(); i++)
        if(a[i] == ' '){
            i1 = a.substr(0, i);
            A = a.substr(i + 1);
            break;
        }
    for(int i = 0; i < b.length(); i++)
        if(b[i] == ' '){
            i2 = b.substr(0, i);
            B = b.substr(i + 1);
            break;
        }
    if(A.compare(B) != 0){
        if(A.compare(B) > 0)
            return 0;
        return 1;
    }
    else{
        if(i1.compare(i2) > 0)
            return 0;
        return 1;
    }
}


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, let, dig;
        int n = logs.size();

        for(int i = 0; i < n; i++){
            char last = logs[i][logs[i].length() - 1];
            if('0' <= last && last <= '9')
                dig.push_back(logs[i]);
            else
                let.push_back(logs[i]);
        }
        sort(let.begin(), let.end(), myComp);

        for(int i = 0; i < dig.size(); i++)
            let.push_back(dig[i]);
        return let;
    }
};
