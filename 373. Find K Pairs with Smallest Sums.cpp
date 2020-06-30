class Node{
public:
    int s;
    int x;
    int y;

    Node(int s, int x, int y){
        this->s = s;
        this->x = x;
        this->y = y;
    }
};

class myComp{
public:
    bool operator()(const Node &a, const Node &b){
        return a.s > b.s;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node, vector<Node>, myComp> pq;
        vector<vector<int>> res;

        if(nums1.empty() || nums2.empty())  return res;
        for(int i = 0; i < k && i < nums1.size(); i++)
            pq.push(Node(nums1[i] + nums2[0], i, 0));
        while(!pq.empty() && k--){
            Node top = pq.top();
            pq.pop();
            res.push_back(vector<int>({nums1[top.x], nums2[top.y]}));
            if(top.y + 1 < nums2.size())
                pq.push(Node(nums1[top.x] + nums2[top.y + 1], top.x, top.y + 1));
        }
        return res;
    }
};
