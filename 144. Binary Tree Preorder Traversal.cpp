class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *t = nullptr;

        t = root;
        while(t || !s.empty()){
            while(t){
                res.push_back(t->val);
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            t = t->right;
        }
        return res;
    }
};
