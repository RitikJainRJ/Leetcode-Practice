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
    int _diameter(TreeNode *root, int &res){
        if(!root)
            return 0;
        else{
            int left = _diameter(root->left, res);
            int right = _diameter(root->right, res);

            if(res < 1 + left + right)
                res = 1 + left + right;
            return 1 + max(left, right);
        }
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root == nullptr)
            return 0;

        int res = 0;
        _diameter(root, res);
        return res - 1;
    }
};
