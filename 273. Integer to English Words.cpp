class Solution {
private:
    string helper(int num){
        vector<string>lessThan20({"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"});
        vector<string>tens({"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"});

        string res;
        if(num >= 100) res = lessThan20[num / 100] + " Hundred" + ((num % 100) ? " " : "") + helper(num % 100);
        else if(num >= 20) res = tens[num / 10] + ((num % 10 ? " " : "")) + helper(num % 10);
        else res = lessThan20[num];
        return res;
    }
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> thousands({"", " Thousand", " Million", " Billion"});
        string res;

        int i = 0;
        while(num){
            if(num % 1000) res = helper(num % 1000) + thousands[i] + (res.empty() ? "" : " ") + res;
            num /= 1000;
            i++;
        }
        return res;
    }
};
