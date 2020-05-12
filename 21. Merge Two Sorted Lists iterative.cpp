class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr, *p = nullptr;
        ListNode *t1 = l1, *t2 = l2;

        if(t1 && !t2)
            return t1;
        if(!t1 && t2)
            return t2;
        while(t1 && t2){
            if(t1->val <= t2->val){
                if(res == nullptr){
                    res = t1;
                    p = res;
                }
                else{
                    p->next = t1;
                    p = p->next;
                }
                t1 = t1->next;
            }
            else{
                if(res == nullptr){
                    res = t2;
                    p = res;
                }
                else{
                    p->next = t2;
                    p = p->next;
                }
                t2 = t2->next;
            }
        }
        if(t2)
            p->next = t2;
        else if(t1)
            p->next = t1;
        return res;
    }
};
