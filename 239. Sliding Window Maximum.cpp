class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q(k);
        vector<int> res;

        for(int i = 0; i < k; i++){
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for(int i = k; i < nums.size(); i++){
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            if(!q.empty() && q.front() <= i - k)
                q.pop_front();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
