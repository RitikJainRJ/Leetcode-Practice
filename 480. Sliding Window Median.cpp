class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> os(nums.begin(), nums.begin() + k);
        multiset<double>::iterator it = next(os.begin(), k / 2);

        for(int i = k; i < nums.size(); i++){
            res.push_back((*it + *prev(it, 1 - k % 2)) * 0.5);
            os.insert(nums[i]);

            if(nums[i] < *it)
                it--;
            if(nums[i - k] <= *it)
                it++;
            os.erase(os.lower_bound(nums[i - k]));
        }
        res.push_back((*it + *prev(it, 1 - k % 2)) * 0.5);
        return res;
    }
};
