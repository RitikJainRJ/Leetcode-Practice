class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> s;
        int i = 0, n = heights.size(), res = 0;

        while(i < n){
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else{
                int temp = s.top();
                s.pop();
                int d = s.empty() ? i : i - s.top() - 1;
                res = max(res, d * heights[temp]);
            }
        }
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            int d = s.empty() ? i : i - s.top() - 1;
            res = max(res, d * heights[temp]);
        }
        return res;
    }
};
