class Solution {
public:
    void dfs(Node *node, unordered_set<Node*> &us, unordered_map<Node*, Node*> &um){
        us.insert(node);
        Node *temp = new Node(node->val);
        um[node] = temp;
        for(int i = 0; i < node->neighbors.size(); i++)
            if(us.find(node->neighbors[i]) == us.end())
                dfs(node->neighbors[i], us, um);
    }

    void clone(Node *node, unordered_set<Node*> &us, unordered_map<Node*, Node*> &um){
        us.insert(node);
        for(int i = 0; i < node->neighbors.size(); i++){
            um[node]->neighbors.push_back(um[node->neighbors[i]]);
            if(us.find(node->neighbors[i]) == us.end())
                clone(node->neighbors[i], us, um);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<Node*, Node*> um;
        unordered_set<Node*> us;

        dfs(node, us, um);
        us.clear();
        clone(node, us, um);
        return um[node];
    }
};
