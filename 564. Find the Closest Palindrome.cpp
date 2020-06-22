#define ll long long

class Solution {
    ll makePalin(ll num, bool isOdd){
        if(num == 0)    return 9;
        ll temp = num;

        if(isOdd)
            temp /= 10;
        while(temp){
            num = num * 10 + temp % 10;
            temp /= 10;
        }
        return num;
    }

public:
    string nearestPalindromic(string s){
        ll num = stoll(s), n = s.length(), k;
        ll curr, prev, next;

        if(num <= 10)
            return to_string(num - 1);
        k = n / 2;
        curr = num;
        while(k--){
            curr /= 10;
        }
        if(to_string(curr).length() != to_string(curr - 1).length()){
            int k = n - 2;
            prev = 9;
            while(k--){
                prev = prev * 10 + 9;
            }
        }
        else
            prev = makePalin(curr - 1, n % 2);
        if(to_string(curr).length() != to_string(curr + 1).length()){
            int k = n;
            next = 1;
            while(k--){
                next = next * 10;
            }
            next += 1;
        }
        else
            next = makePalin(curr + 1, n % 2);
        curr = makePalin(curr, n % 2);

        if(curr == num){
            return curr - prev <= next - curr ? to_string(prev) : to_string(next);
        }
        ll res[] = {prev, curr, next}, m = INT_MAX, ind;
        for(ll i = 0; i < 3; i++)
            if(abs(res[i] - num) < m)
                m = abs(res[i] - num), ind = i;
        return to_string(res[ind]);
    }
};
