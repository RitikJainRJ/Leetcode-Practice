class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> um;
    vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = true;
        if(um.find(val) != um.end())
            res = false;
        nums.push_back(val);
        um[val].insert(nums.size() - 1);
        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(um.find(val) == um.end())
            return false;
        int ind = *(um[val].begin());
        um[val].erase(um[val].begin());
        nums[ind] = nums.back();
        um[nums.back()].insert(ind);
        um[nums.back()].erase(nums.size() - 1);
        nums.pop_back();
        if(um[val].empty())
            um.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
