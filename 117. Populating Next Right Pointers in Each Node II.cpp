/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *c = nullptr, *p = nullptr, *head = nullptr;

        c = root;
        while(c){
            while(c){
                if(c->left){
                    if(p)
                        p->next = c->left;
                    else
                        head = c->left;
                    p = c->left;
                }
                if(c->right){
                    if(p)
                        p->next = c->right;
                    else
                        head = c->right;
                    p = c->right;
                }
                c = c->next;
            }
            c = head;
            p = nullptr;
            head = nullptr;
        }
        return root;
    }
};
