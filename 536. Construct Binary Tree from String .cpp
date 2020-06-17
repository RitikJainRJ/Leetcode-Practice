/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    TreeNode* construct(int &i, string &s){
        int num = 0, sign = 1;
        if(s[i] == '-')
            sign = -1, i++;
        while(i < s.length() && '0' <= s[i] && s[i] <= '9')
            num = 10 * num + (s[i++] - '0');
        TreeNode* root = new TreeNode(num * sign);
        if(s[i] == ')'){
            i++;
            return root;
        }
        else
            root->left = construct(++i, s);
        if(i >= s.length() || s[i] == ')'){
            i++;
            return root;
        }
        else
            root->right = construct(++i, s);
        if(i >= s.length() || s[i] == ')'){
            i++;
            return root;
        }
        return root;
    }

public:
    TreeNode* str2tree(string &s) {
        if(s.empty())
            return nullptr;
        TreeNode *root = nullptr;
        int i = 0;

        root = construct(i, s);
        return root;
    }
};
