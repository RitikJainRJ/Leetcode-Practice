struct Trie{
    unordered_map<char, Trie*> um;
    bool isEnd;
};

Trie* createNode(){
    Trie *node = new Trie;
    node->isEnd = false;
    return node;
}

void insert(Trie **root, string word){
    Trie *temp = nullptr;

    if(*root == nullptr)
        *root = createNode();
    temp = *root;
    for(int i = 0; i < word.length(); i++){
        if(temp->um.find(word[i]) == temp->um.end())
            temp->um[word[i]] = createNode();
        temp = temp->um[word[i]];
    }
    temp->isEnd = true;
}

class Solution {
public:
    void _findWords(vector<vector<char>>& board, Trie *root, int x, int y, vector<string> &res, string ans){
        int xMove[] = {-1, 0, 1, 0};
        int yMove[] = {0, 1, 0, -1};
        char original = board[x][y];
        cout << original << " ";
        if(root->isEnd == true)
            res.push_back(ans);
        board[x][y] = '$';
        for(int i = 0; i < 4; i++){
            int _x = x + xMove[i];
            int _y = y + yMove[i];
            if(0 <= _x && _x < board.size() && 0 <= _y && _y < board[_x].size() && root->um.find(board[_x][_y]) != root->um.end())
                _findWords(board, root->um[board[_x][_y]], _x, _y, res, ans + board[_x][_y]);
        }
        board[x][y] = original;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        unordered_set<string> us;
        string ans;
        Trie *root = nullptr;

        if(words.size() == 0)
            return res;
        for(int i = 0; i < words.size(); i++)
            insert(&root, words[i]);
        for(auto it = root->um.begin(); it != root->um.end(); it++){
            char temp = it->first;
            cout << temp << "--";
            for(int i = 0; i < board.size(); i++)
                for(int j = 0; j < board[i].size(); j++)
                    if(board[i][j] == temp)
                        _findWords(board, root->um[temp], i, j, res, ans + temp);
            cout << endl;
        }
        for(int i = 0; i < res.size(); i++)
            us.insert(res[i]);
        res.clear();
        for(auto it = us.begin(); it != us.end(); it++)
            res.push_back(*it);
        return res;
    }
};
