class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> m(3, INT_MIN);
        vector<int> p(2, INT_MAX);

        for(int i = 0; i < n; i++){
            if(p[1] > nums[i]){
                p[0] = p[1];
                p[1] = nums[i];
            }
            else if(p[0] > nums[i])
                p[0] = nums[i];
            if(m[2] < nums[i]){
                m[0] = m[1];
                m[1] = m[2];
                m[2] = nums[i];
            }
            else if(m[1] < nums[i]){
                m[0] = m[1];
                m[1] = nums[i];
            }
            else if(m[0] < nums[i])
                m[0] = nums[i];
        }
        return max(m[0] * m[1] * m[2], p[0] * p[1] * m[2]);
    }
};
