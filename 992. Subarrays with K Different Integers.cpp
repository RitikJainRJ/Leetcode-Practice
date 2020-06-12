class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        unordered_map<int, int> um1, um2;
        int left1 = 0, left2 = 0, right;
        int c1 = 0, c2 = 0;
        int res = 0;

        for(right = 0; right < A.size(); right++){
            um1[A[right]]++;
            if(um1[A[right]] == 1)
                c1++;
            um2[A[right]]++;
            if(um2[A[right]] == 1)
                c2++;
            if(c1 > k){
                while(um1[A[left1]] != 1){
                    um1[A[left1]]--;
                    left1++;
                }
                um1[A[left1]]--;
                left1++;
                c1--;
            }
            if(c2 >= k){
                while(um2[A[left2]] != 1){
                    um2[A[left2]]--;
                    left2++;
                }
                um2[A[left2]]--;
                left2++;
                c2--;
            }
            res += left2 - left1;
        }
        return res;
    }
};
