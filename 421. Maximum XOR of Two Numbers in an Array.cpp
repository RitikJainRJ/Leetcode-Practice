class TrieNode{
public:
    vector<TrieNode*> children;

    TrieNode(){
        children = vector<TrieNode*>(2);
    }
};

class Solution {
private:
    void insertReverse(TrieNode *&root, int num){
        TrieNode *temp = nullptr;

        if(!root)   root = new TrieNode();
        temp = root;
        int x = 1 << 30;
        for(int i = 0; i <= 30; i++){
            int bit = (num & x) > 0 ? 1 : 0;
            x = x >> 1;

            if(temp->children[!bit] == nullptr)
                temp->children[!bit] = new TrieNode();
            temp = temp->children[!bit];
        }
    }

    int solve(TrieNode *root, int num){
        TrieNode *temp = root;
        int res = 0;

        int x = 1 << 30;
        for(int i = 0; i <= 30; i++){
            int bit = (num & x) > 0 ? 1 : 0;
            x = x >> 1;
            res = res << 1;

            if(!temp)
                return res;
            if(temp->children[bit]){
                temp = temp->children[bit];
                res = res | 1;
            }
            else{
                temp = temp->children[!bit];
            }
        }
        return res;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = nullptr;
        int n = nums.size(), res = 0;

        for(int i = 0; i < n; i++)
            insertReverse(root, nums[i]);
        for(int i = 0; i < n; i++)
            res = max(res, solve(root, nums[i]));
        return res;
    }
};
