class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;      // total gas - total cost
        int tank = 0;       // current gas in tank
        int start = 0;      // candidate starting station

        for(int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];

            total += diff;
            tank += diff;

            // cannot reach next station
            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        if (total >= 0) return start;         
        else return -1;
    }
};