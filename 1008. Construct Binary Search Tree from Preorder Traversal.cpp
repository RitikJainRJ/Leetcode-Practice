class Solution {
private:
    TreeNode* construct(int &ind, vector<int> &preorder, int min, int max){
        if(ind >= preorder.size())
            return nullptr;
        int x = preorder[ind];
        if(!(min < x && x < max))
            return nullptr;
        TreeNode *root = new TreeNode(x);
        ind++;
        root->left = construct(ind, preorder, min, x);
        root->right = construct(ind, preorder, x, max);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return construct(ind, preorder, INT_MIN, INT_MAX);
    }
};
