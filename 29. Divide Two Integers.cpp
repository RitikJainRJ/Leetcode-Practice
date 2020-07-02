class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        int sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;

        dividend = abs(dividend), divisor = abs(divisor);
        while(dividend >= divisor){
            int t = divisor;
            int c = 0;
            while(dividend - t > 0){
                t = t << 1;
                c++;
            }
            if(c != 0)
                c--;
            int q = 1 << c;
            quotient += q;
            dividend = dividend - q * divisor;
        }
        if(sign == 1)
            return quotient;
        return quotient - quotient - quotient;
    }
};
