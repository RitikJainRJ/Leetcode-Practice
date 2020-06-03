class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int K) {
        ListNode *p = nullptr, *c = nullptr, *q = nullptr;
        ListNode *prev = nullptr, *temp = nullptr;
        int k;

        c = head;
        while(c){
            k = K;
            temp = c;
            p = nullptr;
            while(c && k--) c = c->next;
            if(k > 0){
                prev->next = temp;
                break;
            }
            c = temp;
            k = K;
            while(c && k--){
                q = c->next;
                c->next = p;
                p = c;
                c = q;
            }
            if(!prev)   head = p;
            else    prev->next = p;
            prev = temp;
        }
        return head;
    }
};
