/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void _rob(TreeNode *root, unordered_map<TreeNode*, int> &um){
        if(root == nullptr)
            um[root] = 0;
        else if(!root->left && !root->right)
            um[root] = root->val;
        else{
            _rob(root->left, um);
            _rob(root->right, um);
            int lc = 0, llc = 0, lrc = 0;
            int rc = 0, rlc = 0, rrc = 0;
            if(root->left){
                lc = um[root->left];
                llc = um[root->left->left];
                lrc = um[root->left->right];
            }
            if(root->right){
                rc = um[root->right];
                rlc = um[root->right->left];
                rrc = um[root->right->right];
            }
            um[root] = max(lc + rc, root->val + llc + lrc + rlc + rrc);
        }
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> um;
        um[nullptr] = 0;
        _rob(root, um);
        return um[root];
    }
};
