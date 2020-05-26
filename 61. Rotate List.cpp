/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode *head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverse(ListNode *head){
        ListNode *p = nullptr, *c = head, *q = nullptr;

        while(c){
            q = c->next;
            c->next = p;
            p = c;
            c = q;
        }
        return p;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getLength(head);
        ListNode *temp = nullptr, *t = nullptr;

        if(head == nullptr || k % n == 0)
            return head;
        head = reverse(head);
        temp = head;
        k = k % n;
        while(k > 1){
            temp = temp->next;
            k--;
        }
        t = temp->next;
        temp->next = nullptr;
        head = reverse(head);
        t = reverse(t);
        temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = t;
        return head;
    }
};
