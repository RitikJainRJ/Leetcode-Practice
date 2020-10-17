#define ll long long
class Solution {
public:
    bool isPowerOfFour(int n) {
        ll num = n;
        ll x = num ^ (num & -num);
        if(x != 0)
            return false;
        ll y = stoll("1010101010101010101010101010101", nullptr, 2);
        if(num & y)   return true;
        return false;
    }
};
