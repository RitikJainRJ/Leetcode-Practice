class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t1 = head, *t2 = head;

        while(n--)      t2 = t2->next;
        if(!t2)     return t1->next;
        while(t2->next)     t1 = t1->next, t2 = t2->next;
        t1->next = t1->next->next;
        return head;
    }
};
