/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    void leftview(TreeNode* root, vector<int> &res){
        if(!root)    return;
        if(!root->left && !root->right) return;
        res.push_back(root->val);
        if(root->left)
            leftview(root->left, res);
        else
            leftview(root->right, res);
    }

    void bottomview(TreeNode* root, vector<int> &res){
        if(!root)   return;
        if(!root->left && !root->right) res.push_back(root->val);
        bottomview(root->left, res);
        bottomview(root->right, res);
    }

    void rightview(TreeNode* root, vector<int> &res){
        if(!root)    return;
        if(!root->left && !root->right) return;
        if(root->right)
            rightview(root->right, res);
        else
            rightview(root->left, res);
        res.push_back(root->val);
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;

        if(!root)   return res;
        res.push_back(root->val);
        leftview(root->left, res);
        bottomview(root, res);
        rightview(root->right, res);
        return res;
    }
};
