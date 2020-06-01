class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> res(n, -1);
        bool flag = false;
        int i = 0;

        while(i < n){
            if(s.empty() || nums[s.top()] >= nums[i]){
                s.push(i++);
                if(i == n && flag == false)
                    i = 0, flag = true;
            }
            else{
                int t = s.top();
                s.pop();
                res[t] = (res[t] == -1) ? nums[i] : res[t];
            }
        }
        return res;
    }
};
