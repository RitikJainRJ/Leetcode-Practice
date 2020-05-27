class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int n1 = ver1.length(), n2 = ver2.length();
        int i = 0, j = 0;
        int num1, num2;

        while(i < n1 && j < n2){
            num1 = 0;
            while(ver1[i] != '\0' && ver1[i] != '.'){
                num1 = num1 * 10 + (ver1[i] - '0');
                i++;
            }
            i++;
            num2 = 0;
            while(ver2[j] != '\0' && ver2[j] != '.'){
                num2 = num2 * 10 + (ver2[j] - '0');
                j++;
            }
            j++;
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
        }
        while(i < n1){
            if('1' <= ver1[i] && ver1[i] <= '9')
                return 1;
            i++;
        }
        while(j < n2){
            if('1' <= ver2[j] && ver2[j] <= '9')
                return -1;
            j++;
        }
        return 0;
    }
};
