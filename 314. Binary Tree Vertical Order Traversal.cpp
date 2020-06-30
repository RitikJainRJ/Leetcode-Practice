#define pni pair<TreeNode*, int>

class Solution {
private:
    void getMinMax(TreeNode *root, int hd, int &imin, int &imax){
        if(!root)   return;
        imin = min(imin, hd);
        imax = max(imax, hd);
        getMinMax(root->left, hd - 1, imin, imax);
        getMinMax(root->right, hd + 1, imin, imax);
    }

public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> um;
        queue<pni> q;
        int min = INT_MAX, max = INT_MIN;

        if(!root)   return res;
        getMinMax(root, 0, min, max);
        q.push({root, 0});
        while(!q.empty()){
            pni f = q.front();
            q.pop();

            um[f.second].push_back(f.first->val);
            if(f.first->left)
                q.push({f.first->left, f.second - 1});
            if(f.first->right)
                q.push({f.first->right, f.second + 1});
        }
        for(int i = min; i <= max; i++)
            res.push_back(um[i]);
        return res;
    }
};
