class Solution {
public:
    string intToRoman(int num) {
        if(num <= 0)
            return "";
        if(3 >= num) return "I" + intToRoman(num - 1);
        if(num == 4) return "IV";
        if(8 >= num) return "V" + intToRoman(num - 5);
        if(9 == num) return "IX";
        if(39 >= num) return "X" + intToRoman(num - 10);
        if(49 >= num) return "XL" + intToRoman(num - 40);
        if(89 >= num) return "L" + intToRoman(num - 50);
        if(99 >= num) return "XC" + intToRoman(num - 90);
        if(399 >= num) return "C" + intToRoman(num - 100);
        if(499 >= num) return "CD" + intToRoman(num - 400);
        if(899 >= num) return "D" + intToRoman(num - 500);
        if(999 >= num) return "CM" + intToRoman(num - 900);
        else return "M" + intToRoman(num - 1000);
    }
};
