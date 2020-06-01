class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> res;
        stack<int> s;
        int i = 0;

        while(i < nums2.size()){
            if(s.empty() || s.top() >= nums2[i])
                s.push(nums2[i++]);
            else{
                int t = s.top();
                s.pop();
                um[t] = nums2[i];
            }
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            um[t] = -1;
        }
        for(int i = 0; i < nums1.size(); i++)
            res.push_back(um[nums1[i]]);
        return res;
    }
};
