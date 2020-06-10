class Solution {
private:
    bool can(vector<int>&arr, int ind, unordered_set<int> &us){
        if(ind < 0 || ind >= arr.size() || us.find(ind) != us.end())
            return false;
        us.insert(ind);
        if(arr[ind] == 0)
            return true;
        return can(arr, ind + arr[ind], us) || can(arr, ind - arr[ind], us);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> us;

        return can(arr, start, us);
    }
};
