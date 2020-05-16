class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n;
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        n = n1 + n2;

        int l = 0, r = n1; // here we take one more in r.
        while(l <= r){
            int mid1 = (l + r) / 2;
            int leftMax1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int rightMin1 = (mid1 == n1) ? INT_MAX : nums1[mid1];

            int mid2 = (n + 1) / 2 - mid1;
            int leftMax2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int rightMin2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if(leftMax1 <= rightMin2 && leftMax2 <= rightMin1){
                int t1 = max(leftMax1 , leftMax2);
                int t2 = min(rightMin1, rightMin2);
                if(n % 2 == 0)
                    return (t1 + t2) * 0.5;
                else
                    return t1;
            }
            else if(leftMax1 > rightMin2)
                r = mid1 - 1;
            else if(leftMax2 > rightMin1)
                l = mid1 + 1;
        }
        return 1;
    }
};
