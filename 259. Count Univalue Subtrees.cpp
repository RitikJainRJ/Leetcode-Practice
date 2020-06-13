struct info{
    bool isUni;
    int count;
};

class Solution {
private:
    info count(TreeNode *root){
        if(!root)   return {true, 0};
        else{
            info left = count(root->left);
            info right = count(root->right);
            int l = root->left ? root->left->val : root->val;
            int r = root->right ? root->right->val : root->val;

            if(left.isUni && right.isUni && l == root->val && root->val == r){
                return {true, 1 + left.count + right.count};
            }
            return {false, left.count + right.count};
        }
    }

public:
    int countUnivalSubtrees(TreeNode *root) {
        info res = count(root);
        return res.count;
    }
};
