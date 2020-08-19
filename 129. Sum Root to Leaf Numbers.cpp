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
    void solve(int &sum, TreeNode *root, int &res){
        if(!root)   return;
        else if(!root->left && !root->right){
            sum = sum * 10 + root->val;
            res += sum;
            sum /= 10;
        }
        else{
            sum = sum * 10 + root->val;
            solve(sum, root->left, res);
            solve(sum, root->right, res);
            sum /= 10;
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        int res = 0, sum = 0;

        solve(sum, root, res);
        return res;
    }
};
