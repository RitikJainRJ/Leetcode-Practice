#define pii pair<int, int>

class Solution {
private:
    pii solve(TreeNode *root, int &res){
        if(!root)   return {0, 0};
        else{
            pii left = solve(root->left, res);
            pii right = solve(root->right, res);

            res = max({res, 1 + left.second, 1 + right.first});
            return {1 + left.second, 1 + right.first};
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        int res = 0;
        if(!root)   return res;
        solve(root, res);
        return res - 1;
    }
};
