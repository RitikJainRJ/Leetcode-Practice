/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    ListNode* insert(ListNode *head, int x) {
        ListNode *t1 = nullptr, *t2 = nullptr, *n = nullptr;

        if(!head){
            head = new ListNode(x);
            head->next = head;
            return head;
        }
        t1 = head;
        t2 = t1;
        do{
            if(t1->val <= x && x <= t1->next->val){
                t2 = t1;
                break;
            }
            if(t1->val > t1->next->val)
                t2 = t1;
            t1 = t1->next;
        }while(t1 != head);
        n = new ListNode(x);
        n->next = t2->next;
        t2->next = n;
        return head;
    }
};
