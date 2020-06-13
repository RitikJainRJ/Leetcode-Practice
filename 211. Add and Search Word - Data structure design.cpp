class TrieNode{
public:
    unordered_map<char, TrieNode*> um;
    bool isEnd;

    TrieNode(){
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;

    bool _search(int i, TrieNode *t, string& word){
        if(i == word.length())  return t->isEnd;
        else if(word[i] == '.'){
            for(auto it = t->um.begin(); it != t->um.end(); it++){
                if(_search(i + 1, it->second, word))
                    return true;
            }
        }
        else{
            if(t->um.find(word[i]) != t->um.end() && _search(i + 1, t->um[word[i]], word))
                return true;
        }
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *t = root;

        for(int i = 0; i < word.length(); i++){
            if(t->um.find(word[i]) == t->um.end())
                t->um[word[i]] = new TrieNode();
            t = t->um[word[i]];
        }
        t->isEnd = true;
    }

    bool search(string word) {
        TrieNode *t = root;
        return _search(0, t, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
