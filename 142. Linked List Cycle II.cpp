class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)   return nullptr;
        ListNode *slow = head, *fast = head;

        do{
            if(!slow) return nullptr;
            slow = slow->next;
            if(!fast || !fast->next) return nullptr;
            fast = fast->next->next;
        }while(slow != fast);
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
