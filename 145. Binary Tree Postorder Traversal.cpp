class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *t = nullptr;
        if(!root)   return res;

        t = root;
        do{
            while(t){
                if(t->right)
                    s.push(t->right);
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            if(t->right && !s.empty() && t->right == s.top()){
                s.pop();
                s.push(t);
                t = t->right;
            }
            else{
                res.push_back(t->val);
                t = nullptr;
            }
        }while(!s.empty());
        return res;
    }
};
