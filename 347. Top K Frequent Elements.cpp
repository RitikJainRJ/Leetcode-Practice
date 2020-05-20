class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> res;

        for(int i = 0; i < nums.size(); i++)
            um[nums[i]]++;
        for(auto it = um.begin(); it != um.end(); it++){
            int data = it->first;
            int fre = it->second;
            buckets[fre].push_back(data);
        }
        for(int i = nums.size(); i >= 0 && k; i--){
            while(!buckets[i].empty() && k){
                res.push_back(buckets[i].back());
                buckets[i].pop_back();
                k--;
            }
        }
        return res;
    }
};
