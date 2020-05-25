class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int n3 = n1 + n2 + 1;
        string res(n3, '0');

        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int c, k;
        for(int j = 0; j < n2; j++){
            c = 0;
            k = j;
            for(int i = 0; i < n1; i++){
                int a = num2[j] - '0', b = num1[i] - '0', r = res[k] - '0';
                int temp = a * b + c;
                res[k] = ((temp % 10 + r) % 10) + '0';
                c = temp / 10 + (temp % 10 + r) / 10;
                k++;
            }
            if(c != 0)
                res[k] = ((res[k] - '0') + c) + '0';
        }
        while(res[res.length() - 1] == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
