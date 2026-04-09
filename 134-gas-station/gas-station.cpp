class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total_gas = 0;
        int total_cost = 0;
        int starting_index = 0;

        for(int i=0; i<n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }
        if(total_gas < total_cost) return -1;

        int diff = 0;
        total_gas = 0;
        for(int i = starting_index; i<n; i++){
            diff = gas[i] - cost[i];
            total_gas += diff;
            if(total_gas < 0){
                total_gas = 0;
                starting_index = i+1;
            } 
        }
        return starting_index;
    }
};