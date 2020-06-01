class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)   return false;
        ListNode *slow = head, *fast = head;

        do{
            slow = slow->next;
            if(!fast->next) return false;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }while(slow && fast && slow != fast);
        return false;
    }
};
