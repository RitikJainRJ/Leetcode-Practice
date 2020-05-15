class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size(), res = 0;

        int i = 0, j = n - 1;
        while(i < j){
            if(arr[i] <= arr[j]){
                res = max(res, arr[i] * (j - i));
                i++;
            }
            else{
                res = max(res, arr[j] * (j - i));
                j--;
            }
        }
        return res;
    }
};
