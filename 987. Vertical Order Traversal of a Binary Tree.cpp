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
public:
    void getMinMax(TreeNode *root, int hd, int &mi, int &ma){
        if(root == nullptr)
            return;
        if(mi > hd)
            mi = hd;
        if(ma < hd)
            ma = hd;
        getMinMax(root->left, hd - 1, mi, ma);
        getMinMax(root->right, hd + 1, mi, ma);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        int mi = INT_MAX, ma = INT_MIN;
        unordered_map<int, vector<int>> um;
        unordered_map<int, set<int>> um2;

        getMinMax(root, 0, mi, ma);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<TreeNode*, int> temp = q.front();
                q.pop();
                TreeNode *t = temp.first;
                int hd = temp.second;
                um2[hd].insert(t->val);
                if(t->left)
                    q.push({t->left, hd - 1});
                if(t->right)
                    q.push({t->right, hd + 1});
            }
            for(auto it = um2.begin(); it != um2.end(); it++)
                for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
                    um[it->first].push_back(*it2);
            um2.clear();
        }
        for(int i = mi; i <= ma; i++){
            res.push_back(um[i]);
        }
        return res;
    }
};
