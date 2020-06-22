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
    int solve(TreeNode* root, unordered_map<int, int> &um){
        if(!root)   return 0;
        else{
            int left = solve(root->left, um);
            int right = solve(root->right, um);

            um[root->val + left + right]++;
            return root->val + left + right;
        }
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> um;
        vector<int> res;
        int max = INT_MIN;

        solve(root, um);
        for(auto it = um.begin(); it != um.end(); it++)
            if(it->second > max)
                max = it->second;
        for(auto it = um.begin(); it != um.end(); it++)
            if(it->second == max)
                res.push_back(it->first);
        return res;
    }
};
