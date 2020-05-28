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
    int getLength(ListNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->next;
        }
        return count;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = getLength(root), i = 0;
        ListNode *t1 = nullptr, *t2 = nullptr;
        vector<ListNode*> res(k, nullptr);

        t1 = root;
        if(k >= n){
            while(t1){
                res[i++] = t1;
                t2 = t1->next;
                t1->next = nullptr;
                t1 = t2;
            }
            return res;
        }
        int l = n / k, temp;
        int f = n % k;
        while(t1){
            res[i++] = t1;
            temp = l;
            while(temp > 1 || (f > 0 && temp > 0)){
                temp--;
                t1 = t1->next;
            }
            f--;
            t2 = t1->next;
            t1->next = nullptr;
            t1 = t2;
        }
        return res;
    }
};
