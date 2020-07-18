class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0;

        int i = 0, j;
        for(j = 0; i < n; j = (j + 1) % n){
            sum += (gas[j] - cost[j]);
            if((j + 1) % n == i && sum >= 0)
                return i;
            while(sum < 0 && i < n){
                sum -= (gas[i] - cost[i]);
                i++;
            }
        }
        return -1;
    }
};
