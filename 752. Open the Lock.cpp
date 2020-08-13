class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> us(deadends.begin(), deadends.end());
        queue<string> q;
        int res = 0;

        if(us.find("0000") == us.end())
            us.insert("0000"), q.push("0000");
        while(!q.empty()){
            int size = q.size();

            while(size--){
                string f = q.front();
                q.pop();

                if(f == target)
                    return res;
                for(int i = 0; i < f.length(); i++){
                    f[i] = f[i] != '0' ? f[i] - 1 : '9';
                    if(us.find(f) == us.end())
                        us.insert(f), q.push(f);
                    f[i] = f[i] != '9' ? f[i] + 1 : '0';
                    f[i] = f[i] != '9' ? f[i] + 1 : '0';
                    if(us.find(f) == us.end())
                        us.insert(f), q.push(f);
                    f[i] = f[i] != '0' ? f[i] - 1 : '9';
                }
            }
            res++;
        }
        return -1;
    }
};
