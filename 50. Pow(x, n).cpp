class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        double res = myPow(x, n / 2);

        if(n % 2 != 0 && n > 0)
            return x * res * res;
        else if(n % 2 != 0 && n < 0)
            return 1 / x * res * res;
        else
            return res * res;
    }
};
