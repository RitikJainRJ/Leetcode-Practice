class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)   return nullptr;
        ListNode *t1 = nullptr, *t2 = nullptr, *p = nullptr;

        t1 = head;
        t2 = head->next;
        while(t2 && t2->next){
            p = t1;
            t1 = t1->next;
            t2 = t2->next->next;
        }
        TreeNode *root = new TreeNode(t1->val);
        if(p){
            p->next = nullptr;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(t1->next);
        return root;
    }
};
