class Solution {
public:
    int minCost(int n) {
        
        int cost = 0;

        if(n==1) return cost;
        else if(n==2) return cost + 1;
        else{
            while(n>1){
                cost += (n-1);
                n--; 
            }
        } 
        return cost;
    }
};