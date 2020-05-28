class Solution {
private:
    void _longest(TreeNode *root, int len, int prev, int &res){
        if(!root)   return;
        else{
            if(prev + 1 == root->val)
                len++;
            else
                len = 1;
            res = max(res, len);
            _longest(root->left, len, root->val, res);
            _longest(root->right, len, root->val, res);
        }
    }

public:
    int longestConsecutive(TreeNode *root) {
        if(root == nullptr) return 0;
        int res = 1;
        _longest(root, 1, INT_MIN, res);
        return res;
    }
};
