class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *t1 = nullptr, *t2 = nullptr;
        ListNode *p = nullptr, *c = nullptr, *q = nullptr;

        if(m >= n)
            return head;
        t1 = head;
        n = n - m + 1;
        while(m > 2){
            t1 = t1->next;
            m--;
        }
        if(m == 1)
            t2 = t1;
        else
            t2 = t1->next;
        c = t2;
        while(c && n--){
            q = c->next;
            c->next = p;
            p = c;
            c = q;
        }
        if(m == 1)
            head = p;
        else
            t1->next = p;
        t2->next = c;
        return head;
    }
};
