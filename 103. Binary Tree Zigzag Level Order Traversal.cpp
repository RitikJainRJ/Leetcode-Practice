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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        bool flag = false;

        if(!root)
            return res;
        dq.push_back(root);
        while(!dq.empty()){
            int size = dq.size();
            vector<int> ans;

            if(!flag){
                for(int i = 0; i < size; i++)
                    ans.push_back(dq[i]->val);
                flag = true;
            }
            else{
                for(int i = size - 1; i >= 0; i--)
                    ans.push_back(dq[i]->val);
                flag = false;
            }
            res.push_back(ans);
            while(size--){
                TreeNode *node = dq.front();
                dq.pop_front();

                if(node->left)
                    dq.push_back(node->left);
                if(node->right)
                    dq.push_back(node->right);
            }
        }
        return res;
    }
};
