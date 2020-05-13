class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0 || n == 1)
            return n;

        int arr[n];
        int two = 0, three = 0, five = 0;
        arr[0] = 1;
        for(int i = 1; i < n; i++){
            arr[i] = min({arr[two] * 2, arr[three] * 3, arr[five] * 5});
            if(arr[i] == arr[two] * 2) two++;
            if(arr[i] == arr[three] * 3) three++;
            if(arr[i] == arr[five] * 5) five++;
        }
        return arr[n - 1];
    }
};
