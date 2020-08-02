class NumArray {
private:
    int *tree;
    vector<int> nums;
    int n;

    void construct(int node, int s, int e, vector<int> &nums){
        if(s == e){
            tree[node] = nums[s];
            return;
        }
        int mid = (s + e) / 2;
        construct(node * 2, s, mid, nums);
        construct(node * 2 + 1, mid + 1, e, nums);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int sum(int node, int qs, int qe, int ss, int se){
        if(qs <= ss && se <= qe)
            return tree[node];
        if(qe < ss || se < qs)
            return 0;
        int mid = (ss + se) / 2;
        return sum(node * 2, qs, qe, ss, mid) + sum(node * 2 + 1, qs, qe, mid + 1, se);
    }

    void _update(int node, int s, int e, int ind, int diff){
        if(ind < s || e < ind)
            return;
        tree[node] += diff;
        if(s != e){
            int mid = (s + e) / 2;
            _update(node * 2, s, mid, ind, diff);
            _update(node * 2 + 1, mid + 1, e, ind, diff);
        }
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        if(n == 0)
            return;
        int size = 2 * pow(2, ceil(log2(n)));
        tree = new int[size];

        construct(1, 0, n - 1, nums);
    }

    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        _update(1, 0, n - 1, i, diff);
    }

    int sumRange(int i, int j) {
        return sum(1, i, j, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
