struct Node{
    int key;
    int val;
    int fre;
    Node(int k, int v, int f) : key{k}, val{v}, fre{f} {}
};

class LFUCache {
private:
    int n;
    int s;
    unordered_map<int, list<Node>::iterator> um;
    map<int, list<Node>> om;

public:
    LFUCache(int capacity) {
        n = capacity;
        s = 0;
    }

    int get(int key) {
        if(um.find(key) == um.end())
            return -1;
        int val = um[key]->val;
        int fre = um[key]->fre;
        om[fre].erase(um[key]);
        if(om[fre].empty())
            om.erase(fre);
        fre++;
        om[fre].push_front(Node(key, val, fre));
        um[key] = om[fre].begin();
        return val;
    }

    void put(int key, int value) {
        if(um.find(key) != um.end()){
            um[key]->val = value;
            get(key);
        }
        else if(s < n){
            Node temp = Node(key, value, 1);
            om[1].push_front(temp);
            um[key] = om[1].begin();
            s++;
        }
        else if(s == n){
            if(om.empty())
                return;
            auto it = om.begin();
            um.erase(it->second.back().key);
            it->second.pop_back();
            if(it->second.empty())
                om.erase(it->first);

            Node temp = Node(key, value, 1);
            om[1].push_front(temp);
            um[key] = om[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
