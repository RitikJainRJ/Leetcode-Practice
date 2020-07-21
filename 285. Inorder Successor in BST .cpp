class Solution {
private:
    TreeNode *prev = nullptr;

    void reverseInorder(TreeNode *root, TreeNode *p, TreeNode *&res){
        if(root && !res){
            reverseInorder(root->right, p, res);
            if(root == p)
                res = prev;
            prev = root;
            reverseInorder(root->left, p, res);
        }
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *res = nullptr;

        reverseInorder(root, p, res);
        return res;
    }
};
