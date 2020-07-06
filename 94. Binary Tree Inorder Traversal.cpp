class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *t = nullptr;

        t = root;
        while(t || !s.empty()){
            while(t){
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            res.push_back(t->val);
            t = t->right;
        }
        return res;
    }
};
