class TrieNode{
public:
    unordered_map<char, TrieNode*> um;
    int isEnd;

    TrieNode(){
        isEnd = -1;
    }
};

class WordFilter {
private:
    TrieNode *root1, *root2;
    unordered_map<string, int> um;

    void findWord(int i, string &s, string word, TrieNode *t, unordered_set<string> &us){
        if(i >= s.length()){
            if(t->isEnd != -1)
                us.insert(word);
            for(auto it = t->um.begin(); it != t->um.end(); it++){
                findWord(i, s, word + it->first, it->second, us);
            }
        }
        else{
            if(t->isEnd != -1)
                us.insert(word);
            if(t->um.find(s[i]) != t->um.end())
                findWord(i + 1, s, word + s[i], t->um[s[i]], us);
        }
    }

public:
    WordFilter(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root1 = new TrieNode();
        root2 = new TrieNode();
        TrieNode *t = nullptr, *p = nullptr;

        for(int i = 0; i < words.size(); i++){
            um[words[i]] = i;
            t = root1, p = root2;
            int n = words[i].size();
            for(int j = 0; j < n; j++){
                if(t->um.find(words[i][j]) == t->um.end())
                    t->um[words[i][j]] = new TrieNode();
                t = t->um[words[i][j]];
                if(p->um.find(words[i][n - 1 - j]) == p->um.end())
                    p->um[words[i][n - 1 - j]] =  new TrieNode();
                p = p->um[words[i][n - 1 - j]];
            }
            t->isEnd = i;
            p->isEnd = i;
        }
    }

    int f(string prefix, string suffix) {
        unordered_set<string> us1, us2;
        reverse(suffix.begin(), suffix.end());
        findWord(0, prefix, "", root1, us1);
        findWord(0, suffix, "", root2, us2);
        int res = -1;

        for(auto it = us1.begin(); it != us1.end(); it++){
            string temp = *it;
            reverse(temp.begin(), temp.end());
            if(us2.find(temp) != us2.end())
                res = max(res, um[*it]);
        }

        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
