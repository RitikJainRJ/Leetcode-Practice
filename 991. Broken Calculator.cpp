class Solution {
public:
    int brokenCalc(int X, int Y) {
        int count = 0;

        while(X != Y){
            if(Y <= X){
                count += X - Y;
                break;
            }
            if(Y % 2 != 0)  Y++, count++;
            Y /= 2, count++;
        }
        return count;
    }
};
