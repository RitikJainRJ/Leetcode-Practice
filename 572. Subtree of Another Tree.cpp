
class Solution {
private:
    bool isValid(TreeNode *s, TreeNode *t){
        if(!s && !t)    return true;
        else if(!s)     return false;
        else if(!t)     return false;
        else{
            if(s->val == t->val)
                return isValid(s->left, t->left) && isValid(s->right, t->right);
            return false;
        }
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)  return false;
        else{
            if(isValid(s, t))
                return true;
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};
