class Solution {
private:
    int convert(string s, int ind){
        if(ind >= s.length())   return 0;
        if(s[ind] == 'I' && s[ind + 1] == 'V')  return 4 + convert(s, ind + 2);
        if(s[ind] == 'I' && s[ind + 1] == 'X')  return 9 + convert(s, ind + 2);
        if(s[ind] == 'I')   return 1 + convert(s, ind + 1);
        if(s[ind] == 'V')   return 5 + convert(s, ind + 1);
        if(s[ind] == 'X' && s[ind + 1] == 'L')  return 40 + convert(s, ind + 2);
        if(s[ind] == 'X' && s[ind + 1] == 'C')  return 90 + convert(s, ind + 2);
        if(s[ind] == 'X')   return 10 + convert(s, ind + 1);
        if(s[ind] == 'L')   return 50 + convert(s, ind + 1);
        if(s[ind] == 'C' && s[ind + 1] == 'D')  return 400 + convert(s, ind + 2);
        if(s[ind] == 'C' && s[ind + 1] == 'M')  return 900 + convert(s, ind + 2);
        if(s[ind] == 'C')   return 100 + convert(s, ind + 1);
        if(s[ind] == 'D')   return 500 + convert(s, ind + 1);
        else    return 1000 + convert(s, ind + 1);
    }

public:
    int romanToInt(string s) {
        return convert(s, 0);
    }
};
