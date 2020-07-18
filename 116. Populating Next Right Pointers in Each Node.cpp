class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        queue<Node*> q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();

            while(size--){
                Node *f = q.front();
                q.pop();

                f->next = size == 0 ? nullptr : q.front();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
        }
        return root;
    }
};
