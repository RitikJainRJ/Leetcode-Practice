#define ll long long
class Solution {
public:
    string fractionToDecimal(int N, int D) {
        string left, right, sign;
        unordered_map<int, int> um;
        ll n = N, d = D;

        if(n == 0)
            return "0";
        sign = (n > 0 && d > 0) || (n < 0 && d < 0) ? "" : "-";
        n = abs(n), d = abs(d);
        left = to_string(n / d);
        n = n % d;
        while(n){
            if(um.find(n) != um.end()){
                right.insert(um[n], "(");
                right += ')';
                break;
            }
            um[n] = right.length();
            n = n * 10;
            ll q = n / d;
            n = n % d;
            right += to_string(q);
        }
        if(right.empty())
            return sign + left;
        return sign + left + "." + right;
    }
};
