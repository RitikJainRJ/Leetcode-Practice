class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> us;
        vector<vector<int>> move({{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 1, 5}, {2, 4}});
        queue<string> q;
        string s;
        int l = 0;

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                s += (board[i][j] + '0');
        q.push(s);
        us.insert(s);
        while(!q.empty()){
            int size = q.size();

            while(size--){
                string f = q.front();
                q.pop();
                int i;

                if(f == "123450")
                    return l;
                for(i = 0; i < 6; i++)
                    if(f[i] == '0')
                        break;
                for(int j = 0; j < move[i].size(); j++){
                    swap(f[i], f[move[i][j]]);

                    if(us.find(f) == us.end())
                        us.insert(f), q.push(f);
                    swap(f[i], f[move[i][j]]);
                }
            }
            l++;
        }
        return -1;
    }
};
