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
    void _kthSmallest(TreeNode *root, int &k, int &res){
        if(!root || !k)
            return;
        _kthSmallest(root->left, k, res);
        k--;
        if(k == 0)
            res = root->val;
        _kthSmallest(root->right, k, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = 0;
        _kthSmallest(root, k, res);
        return res;
    }
};
