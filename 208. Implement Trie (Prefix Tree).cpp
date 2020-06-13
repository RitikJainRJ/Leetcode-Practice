class TrieNode{
public:
    unordered_map<char, TrieNode*> um;
    bool isEnd;

    TrieNode(){
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *temp = root;

        for(int i = 0; i < word.length(); i++){
            if(temp->um.find(word[i]) == temp->um.end())
                temp->um[word[i]] = new TrieNode();
            temp = temp->um[word[i]];
        }
        temp->isEnd = true;
    }

    bool search(string word) {
        TrieNode *temp = root;

        for(int i = 0; i < word.length(); i++){
            if(temp->um.find(word[i]) == temp->um.end())
                return false;
            temp = temp->um[word[i]];
        }
        return temp->isEnd;
    }

    bool startsWith(string word) {
        TrieNode *temp = root;

        for(int i = 0; i < word.length(); i++){
            if(temp->um.find(word[i]) == temp->um.end())
                return false;
            temp = temp->um[word[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
