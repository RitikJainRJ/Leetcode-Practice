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
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        bool isX = false, isY = false;

        q.push(root);
        while(!q.empty()){
            int size = q.size();

            while(size--){
                TreeNode *front = q.front();
                q.pop();
                if(front->val == x) isX = true;
                if(front->val == y) isY = true;

                if(front->left && front->right){
                    if(front->left->val == x && front->right->val == y)
                        return false;
                    else if(front->left->val == y && front->right->val == x)
                        return false;
                }
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            if(isX && isY)
                return true;
            else if(isX || isY)
                return false;
        }
        return false;
    }
};
