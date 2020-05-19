class Solution {
private:
    int partition(vector<int>& nums, int l, int r){
        int i = l - 1;
        int pivot = nums[r];

        for(int j = l; j <= r; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {

        int l = 0, r = nums.size() - 1;
        k = nums.size() - k;

        while(l <= r){
            int p = partition(nums, l, r);
            if(p == k)
                return nums[p];
            else if(p < k)
                l = p + 1;
            else if(p > k)
                r = p - 1;
        }
        return -1;
    }
};
