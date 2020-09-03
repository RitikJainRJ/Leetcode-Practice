#define MAX 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size(), res = 0;
        stack<int> s;
        int i = 0;

        while(i < n){
            if(s.empty() || nums[s.top()] < nums[i])
                s.push(i++);
            else{
                int top = s.top();
                s.pop();
                int a = s.empty() ? top + 1 : top - s.top();
                int b = i - top;
                res = ((nums[top] * a * b + res) % MAX);
            }
        }
        while(!s.empty()){
            int top = s.top();
            s.pop();
            int a = s.empty() ? top + 1 : top - s.top();
            int b = i - top;
            res = (nums[top] * a * b + res) % MAX;
        }
        return res;
    }
};
