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
    void _pathSum(TreeNode *root, int sum, vector<int> &ans, vector<vector<int>> &res){
        if(!root)
            return;
        if(!root->left && !root->right){
            sum -= root->val;
            ans.push_back(root->val);
            if(sum == 0)
                res.push_back(ans);
            ans.pop_back();
        }
        else{
            sum -= root->val;
            ans.push_back(root->val);
            _pathSum(root->left, sum, ans, res);
            _pathSum(root->right, sum, ans, res);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> ans;

        _pathSum(root, sum, ans, res);
        return res;
    }
};
