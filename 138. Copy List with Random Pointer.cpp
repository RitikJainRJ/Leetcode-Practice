class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node *t1 = nullptr, *t2 = nullptr;
        Node *res = nullptr;

        t1 = head;
        while(t1){
            t2 = t1->next;
            t1->next = new Node(t1->val);
            t1 = t1->next;
            t1->next = t2;
            t1 = t1->next;
        }

        res = head->next;
        t1 = head;
        while(t1){
            if(t1->random)
                t1->next->random = t1->random->next;
            t1 = t1->next->next;
        }
        t1 = head;
        t2 = res;
        while(1){
            t1->next = t2->next;
            t1 = t1->next;
            if(!t1)
                break;
            t2->next = t1->next;
            t2 = t2->next;
        }
        return res;
    }
};
