class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int n3 = max(n1, n2) + 1;
        string res(n3, '0');

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0, c = 0;
        while(i < n1 && i < n2){
            int temp = (num1[i] - '0') + (num2[i] - '0') + c;
            c = temp / 10;
            res[i] = (temp % 10) + '0';
            i++;
        }
        while(i < n1){
            int temp = (num1[i] - '0') + c;
            c = temp / 10;
            res[i] = (temp % 10) + '0';
            i++;
        }
        while(i < n2){
            int temp = (num2[i] - '0') + c;
            c = temp / 10;
            res[i] = (temp % 10) + '0';
            i++;
        }
        if(c > 0){
            res[i] = c + '0';
        }
        while(res.length() != 1 && res[res.length() - 1] == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
