class Solution {
private:
    int height(TreeNode* root){
        if(!root)   return -1;
        return 1 + height(root->left);
    }

public:
    int countNodes(TreeNode* root) {
        int h = height(root);

        if(h < 0)
            return 0;
        int rh = height(root->right);
        if(h == rh + 1)
            return (1 << h) + countNodes(root->right);
        else
            return (1 << (rh + 1)) + countNodes(root->left);
    }
};
