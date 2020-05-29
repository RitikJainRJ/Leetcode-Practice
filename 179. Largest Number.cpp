class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        int i = 0;

        sort(nums.begin(), nums.end(), [&](int &a, int &b){
            string A = to_string(a);
            string B = to_string(b);
            string AB = A + B;
            string BA = B + A;
            if(AB.compare(BA) > 0)
                return true;
            else
                return false;
        });
        while(i < nums.size() && nums[i] == 0)
            i++;
        for(; i < nums.size(); i++)
            res += to_string(nums[i]);
        if(res.empty())
            return "0";
        return res;
    }
};
