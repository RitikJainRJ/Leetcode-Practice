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
    int _maxPathSum(TreeNode *root, int &res){
        if(root == nullptr)
            return 0;
        else{
            int left = _maxPathSum(root->left, res);
            int right = _maxPathSum(root->right, res);

            if(res < left + right + root->val)
                res = left + right + root->val;
            if(root->val + max(left, right) < 0)
                return 0;
            return root->val + max(left, right);
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res = INT_MIN;

        _maxPathSum(root, res);
        return res;
    }
};
