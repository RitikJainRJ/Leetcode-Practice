class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *t1 = nullptr, *t2 = nullptr, *head2 = head->next;

        t1 = head;
        t2 = head2;
        while(t2){
            t1->next = t2->next;
            if(!t1->next)
                break;
            t1 = t1->next;
            t2->next = t1->next;
            t2 = t2->next;
        }
        t1->next = head2;
        return head;
    }
};
