/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void getAnnoted(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &um){
        if(!root)   return;
        else{
            if(root->left)
                um[root->left] = root;
            if(root->right)
                um[root->right] = root;
            getAnnoted(root->left, um);
            getAnnoted(root->right, um);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> us;
        unordered_map<TreeNode*, TreeNode*> um;

        um[root] = nullptr;
        getAnnoted(root, um);
        q.push(target);
        us.insert(target);
        while(!q.empty() && k--){
            int size = q.size();

            while(size--){
                TreeNode* f = q.front();
                q.pop();

                if(f->left && us.find(f->left) == us.end())
                    q.push(f->left), us.insert(f->left);
                if(f->right && us.find(f->right) == us.end())
                    q.push(f->right), us.insert(f->right);
                if(um[f] && us.find(um[f]) == us.end())
                    q.push(um[f]), us.insert(um[f]);
            }
        }
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
